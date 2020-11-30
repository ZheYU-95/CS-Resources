#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <unordered_map>
#include <memory>
#include <assert.h>
using namespace std;

/* 1. 实现大顶堆 */
template<class T>
class Maxheap {
public:
    Maxheap(int size) {
        if(size<1) {
            throw"capacity must be >= 1";
        }
        else {
            currentSize=0;
            
            capacity = size;
            heap=new T[capacity+1]; //heap[0]不使用
        }
    }
    ~Maxheap() {delete []heap;}
    bool Isempty() {return currentSize==0;}
    void push(T item) {  //插入操作
        if(currentSize==capacity)
            throw"Maxheap is full";
        else {
            currentSize++;
            int currentNode = currentSize;// 元素的插入位置初始化为最后
            while(currentNode > 1 && heap[currentNode/2] < item) {  //(从下往上)进行调整
                heap[currentNode] = heap[currentNode/2];   // 父节点换下来
                currentNode = currentNode/2;
            }
            heap[currentNode]=item; //插入元素
        }
    }
    void pop() {  //删除操作
        if(Isempty())
            throw"heap is empty ,cannot delete";
        else {
            T last=heap[currentSize];  //将最后一个元素初始化为根
            currentSize--;
            int currentNode = 1;       
            int child = 2;
            while(child<=currentSize) {  //（从上往下）进行调整
                if(child < currentSize && heap[child] < heap[child+1]) child++;
                if(last>=heap[child]) break;
                else {
                    heap[currentNode] = heap[child];
                    currentNode = child;
                    child = child * 2;
                }
            }
            heap[currentNode] = last; 
        }
    }
    T top() {return heap[1];}
private:
    T *heap;
    int currentSize;
    int capacity;
};

/* int main() {
  Maxheap<int> H(100); //创建容量为100的堆
  H.push(20);
  H.push(30);
  H.push(15);
  H.push(40);
  H.push(90);
  cout<< "max element at top of Heap: " << H.top() << endl;
  H.pop();
  cout<< "max element at top of Heap: " << H.top() <<endl;
  system("pause");
  return 0;
} */







/* 2. 哈希表 */

// 哈希列表项：先声明一个哈希列表项的类，来封装key和value。
// 之所以需要在表项中存储key是因为碰撞的存在，往往不能够通过散列函数直接得到地址，还需要进一步的判断，因此列表项中需要存储key值
class HashItem {
    int key, val;
public:
    HashItem(int k, int v) : key(k), val(v) {}
    const int getKey() {return key;}
    const int getVal() {return val;}
};

// 哈希表
class HashTable {
    static const int SIZE = 7;
    HashItem** table;   // 注意这是二级指针，指向HashItem*
public:
    HashTable() {
        table = new HashItem*[SIZE]();   // 括号是为了初始化为0
    }
    void set(int key, int val) {
        int idx = key%SIZE;
        // shared_ptr<HashItem> tmp = make_shared<HashItem>(key, val);
        while (table[idx] && table[idx]->getKey()!=key) {
            idx = (idx+1)%SIZE;   // SIZE不够大时，这里面临死循环的问题
        }
        if (table[idx]) delete table[idx];
        table[idx] = new HashItem(key, val);
    }
    const int getVal(int key) {
        int idx = key%SIZE;
        while(table[idx] && table[idx]->getKey() != key) {
            idx = (idx+1)%SIZE;           // SIZE不够大时，这里也面临死循环的问题
        }
        return table[idx] ? table[idx]->getVal() : -1;      // 注意这里需要判断key不存在的情况
    }
    ~HashTable(){
        for(int i=0; i<SIZE; i++)
            if(table[i]) delete table[i];
        delete[] table;                     // 别忘了table本身也是要销毁的
    }
};
/* int main() {
    HashTable h;
    h.set(8, 1);
    h.set(15, 2);
    cout << h.getVal(8) << " " << h.getVal(15) << " ";
    return 0;
}
 */








/* 3. 堆排序 */ 

#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;

//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度
void heapBuild(int* a,int root,int length) {
	int lchild = root*2+1;//根节点的左子结点下标
	if (lchild < length)//左子结点下标不能超出数组的长度
	{
		int flag = lchild;//flag保存左右节点中最大值的下标
		int rchild = lchild+1;//根节点的右子结点下标
		if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
		{
			if (a[rchild] > a[flag])//找出左右子结点中的最大值
			{
				flag = rchild;
			}
		}
		if (a[root] < a[flag])
		{
			//交换父结点和比父结点大的最大子节点
			swap(a[root],a[flag]);
			//从此次最大子节点的那个位置开始递归建堆
			heapBuild(a,flag,length);
		}
	}
}

void heapSort(int* a,int len) {
	for (int i = len/2-1; i >= 0; --i)//从最后一个叶子节点的父节点开始建堆 len/2-1
	{
		heapBuild(a,i,len);
	}

	for (int j = len-1; j > 0; --j)//j表示数组此时的长度，因为len长度已经建过了，从len-1开始
	{
		swap(a[0],a[j]);//交换首尾元素,将最大值交换到数组的最后位置保存
		heapBuild(a,0,j);//去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
	}

}

/* int main(int argc, char **argv)
{
	clock_t Start_time = clock();
	int a[11] = {12,45,748,12,56,3,89,4,48,2,18};   // 11
    int len = sizeof(a)/sizeof(int);
	heapSort(a,len);
 	for (size_t i = 0; i < len; ++i) cout<<a[i]<<" ";
	clock_t End_time = clock();
	cout<<endl;
	cout<<"Total running time is: "<<static_cast<double>(End_time-Start_time)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
	// cin.get();
	return 0;
}
 */










/* 4. strcpy, strncpy, memcpy, strcmp等的实现 */
char* my_strcpy(char* dest, char* src) {
    assert(dest!=nullptr && src!=nullptr);  // 判断地址是否为空，个人感觉可以使用断言
    char* temp = dest;  // 拷贝是dest会移动，而最终要返回的是拷贝后字符串的起始地址，因此要先保存dest的地址，便于最终返回
    while (*src != '\0') *temp++ = *src++;  // 参数只有两个地址，没有拷贝的长度。拷贝到'\0'时就会终止，要保证最终dest末尾是'\0'。
    *temp = '\0';

    return dest;
}

char* my_strncpy(char* dest, char* src, size_t num) {
    assert(dest!=nullptr && src!=nullptr);
    int i = 0;
    char* temp = dest;
    while (i++ < num && *src!='\0') *temp++ = *src++;
    *temp = '\0';

    return dest;
}

void* mymemcpy(void* dest, void* src, int len) {
    /* strncpy只能复制字符串，但memcpy对类型没有要求。strncpy有两个终止条件，memcpy只有一个终止条件，那就是复制n个字节。（n是memcpy的第三个参数）
       要特别注意目的地址和源地址重合的问题，拷贝前要加以判断。实现这个函数时一般要把原来的指针类型转换成char*，这样每次移动都是一个字节。 */
    int i=0;
    char* tempdest=(char*)dest;
    char* tempsrc=(char*)src;
    if(tempdest<tempsrc || tempdest>(tempsrc+len-1)) {
        while(i<len) {
            *tempdest++ = *tempsrc++;
            i++;
        }
    }
    else {
        // 如果dest落在src与sec+len-1之间，二者要同时从最后向前赋值，避免被覆盖
        tempdest+=len;
        tempsrc+=len;
        i=len;
        while(i>0) {
            *tempdest-- = *tempsrc--;
            i--;
        }
    }
    return dest;
}
 

int my_strncmp(char* s1, char* s2, size_t n) {
  if (!n) return(0); //n为无符号整形变量;如果n为0,则返回0
  while (--n && *s1!='\0' && *s1 == *s2) {
     s1++; s2++;
  }
  if (*s1-*s2 > 0) return 1;
  else if (*s1-*s2 < 0) return -1;
  else return 0;
}

int my_strlen(const char *str)   
{     
	if ('\0' == *str)  
		return 0;           
	else        
		return strlen(str+1) + 1;         
}
int main() {
    char a[] = "hello!";
    char b[10];
    my_strncpy(b, a, 5);
    for (int i = 0; i < 10; i++) cout << *(b+i) << " ";
}








/* 5. string类的构造析构拷贝函数 */

class String{
public:
    char *m_data;

    // 传值构造函数
    String (const char *str = nullptr) {   // 只有 const 类型，才能接收 const 对象和非 const 对象参数
        if (str == nullptr) {   // 初始默认值设为nullptr，默认构造函数
            m_data = new char[1];
            *m_data = '\0';
            cout << "Default constructor" << endl;
        }
        else {
            int len = strlen(str);   // 求长度不能用sizeof(str)，因为str是常量指针，指针总是占4B内存，求数组长度要用内置函数strlen(str)
            m_data = new char[len+1];
            strncpy(m_data, str, len+1);
            cout << "Pass argument constructor" << endl;
        }
    }
    // 引用构造函数
    String (const String &other) {    // 使用引用直接传对象实体进来，就不会在实参匹配时调用拷贝构造函数了，规避递归使用拷贝构造的死循环问题
        int len = strlen(other.m_data);
        m_data = new char[len+1];
        strncpy(m_data, other.m_data, len+1);
        cout << "Copy constructor" << endl;
    }
    // 移动构造函数
    String (String &&other) {   // 移动操作直接移动内存数据，根本不需要重新分配内存空间
        m_data = other.m_data;
        other.m_data = nullptr;
        cout << "Move constructor" << endl;
    }
    
    ~String() {
        delete[] m_data;
        cout << "Destructor" << endl;
    }

    // 拷贝赋值
    String &operator=(const String &other) {   // 注意好内存空间分配前，自赋值的检查，本对象的内存空间的释放
        if (this != &other) {
            if (!m_data) delete[] m_data;
            int len = strlen(other.m_data);
            m_data = new char[len+1];
            strncpy(m_data, other.m_data, len+1);
        }
        cout << "Copy assignment" << endl;
        return *this;
    }
    // 移动赋值
    String &operator=(String &&other) {
        if (this != &other) {
            delete[] m_data;
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        cout << "Move assignment" << endl;
        return *this;
    }


};  

/* int main()
{
    {
        // 测试：默认构造
        String s1("Hello!");
        String s2(move(s1));
        cout << s2.m_data << " " << s1.m_data << endl;
        // 测试：自动析构

    }
    return 0;
} */







/* 6. 用两个栈实现队列 */
// stack1只负责进入;stack2只负责取出
// 只有stack2为空时才把stack1的所有元素倾倒进stack2中，因为无论怎么添加下一个要删除的早已经定了 

template <class T>
class CQueue {
    stack<T> stack1,stack2;
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(T value) {
        stack1.push(value);
    }
    
    T deleteHead() {
        // 如果第二个栈为空
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        if (stack2.empty()) {
            return -1;
        } else {
            T deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }

    T back() {
        if (!stack1.empty()) return stack1.top();
        // else return INT_MIN;
    }

    T front() {
        if (!stack2.empty()) return stack2.top();
        // else return INT_MIN;
    }
};

/* int main() {
    CQueue<char>* obj = new CQueue<char>();
    obj->appendTail('a');
    obj->appendTail('b');
    obj->appendTail('c');
    char param_1 = obj->deleteHead();
    char param_2 = obj->deleteHead();
    cout << param_1 << " " << param_2 << endl;
    cout << obj->front();
    return 0;
} */





/* 7.智能指针
在以下三种情况下会引起引用计数的变更：

调用构造函数时： SmartPointer p(new Object());
赋值构造函数时： SmartPointer p(const SmartPointer &p);
赋值时：SmartPointer p1(new Object()); SmartPointer p2 = p1;
 */

class Counter {
    friend class SmartPointPro;
public:
    Counter(){
        ptr = NULL;
        cnt = 0;
    }
    Counter(Object* p){
        ptr = p;
        cnt = 1;
    }
    ~Counter(){
        delete ptr;
    }

private:
    Object* ptr;
    int cnt;
};

class SmartPointPro {
public:
    SmartPointerPro(Object* p){
        ptr_counter = new Counter(p);
    }
    SmartPointerPro(const SmartPointerPro &sp){
        ptr_counter = sp.ptr_counter;
        ++ptr_counter->cnt;
    }
    SmartPointerPro& operator=(const SmartPointerPro &sp){
        ++sp.ptr_counter->cnt;
        --ptr_counter.cnt;
        if(ptr_counter.cnt == 0)
            delete ptr_counter;
        ptr_counter = sp.ptr_counter;
    }
    ~SmartPointerPro(){
        --ptr_counter->cnt;
        if(ptr_counter.cnt == 0)
            delete ptr_counter;
    }
private:
    Counter *ptr_counter;
};






/* 8.构建vector类 */
# define MIN_ARRAY_CAPACITY 8

class Array{
    int _capacity; // 数组分配的空间大小
    int _curSize; // 数组元素个数
    int _newNum;   // 扩容次数
    int *_ptr;  // 指向动态分配的数组
public:
    // 构造函数，s代表数组元素的个数
    Array(int s = 0) : _capacity(s), _curSize(0), _newNum(0) {
        if (s==0) _ptr = nullptr;
        else _ptr = new int[s];
    }
    // 复制构造函数
    Array(Array &a) {
        if (!a._ptr) {
            _capacity = 0;
            _ptr = nullptr;
            _curSize = 0;
            _newNum = 0;
        }
        else {
            _ptr = new int[a._capacity];
            memcpy(_ptr, a._ptr, sizeof(int)*a._capacity);
            _capacity = a._capacity;
            _curSize = a._curSize;
        }
    }
    // 析构函数
    ~Array() {
        if (_ptr) delete[] _ptr;
    }
    // 重载赋值=运算符函数，用于数组对象间的赋值
    Array &operator=(const Array &a) {
        // 防止a = a这样的赋值出现错误
        if (_ptr = a._ptr) return *this;
        // 如果a里面的数组是空的
        if (!a._ptr) {
            if (_ptr) delete [] _ptr;
            _ptr = nullptr;
            _capacity = 0;
            _curSize = 0;
            _newNum = 0;
            return *this;
        }
        // 如果原来空间不够大，重新分配内存空间
        if (a._capacity > _capacity) {
            if (_ptr) delete [] _ptr;
            _ptr = new int[a._capacity];
        }
        memcpy(_ptr, a._ptr, sizeof(int)*a._capacity);
        _capacity = a._capacity;
        return *this;
    }
    // 重载[]运算符函数，用于获取数组下标对应的值
    int &operator[](int i) {
        return _ptr[i];
    }
    // 添加一个元素到数组末尾： 提前分配好一个 n 大小的空间，当数组大小不够的时候，则才继续重新分配 2n 大小的空间，以此类推
    void push_back(int v) {
        if (_ptr) {
            if (_curSize+1 >= _capacity) {
                ++_newNum;
                int newSize = _capacity + MIN_ARRAY_CAPACITY * _newNum;
                int *tmpPtr = new int[newSize];
                memcpy(tmpPtr, _ptr, sizeof(int)*_capacity);
                delete [] _ptr;
                _ptr = tmpPtr;
                _capacity = newSize;
            }
        }
        else _ptr = new int[1];
        _ptr[_curSize] = v;
        ++_curSize;
    }
    // 删除数组末尾的元素
    void pop_back() {}
    // 获取数组的长度
    int length() {
        return _curSize;
    }
    // 获取数组的大小
    int size() {
        return _capacity;
    }
};






/* 9.并查集算法 */
//union findRoot 算法
class UF {
    int cnt;  // 连通个数
    int *parent; // 节点的父节点
    int *size;  // 节点的重量
    
public:
    // 构造函数初始化
    UF(int n) : cnt(n) {
        parent = new int[n];
        size = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] =i;
            size[i] = 1;
        }
    }
    ~UF() {
        delete []parent;
        delete []size;
    }
    // 寻找 x 节点的父节点
    int findRoot(int x) {
        // 路径压缩，尽量降低树高
        if (x != parent[x]) parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    
    // 节点p 和 节点 q 连通
    void Union(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if(rootP == rootQ) return;
        // 小树接在大树下比较平衡
        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += rootP;
        }
        cnt--;    //连通个数 -1
    }
    
    //判断节点p 和 节点 q 是否连通
    bool connected(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        return rootP == rootQ;
    }

    //返回当前连通个数
    int count_num(){
        return cnt;
    }
};





/* 10.LRU */
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity), _size(0) {
        // 使用伪头部和伪尾部节点
        _cache.reserve(capacity);
        _head = new DLinkedNode();
        _tail = new DLinkedNode();
        _head->next = _tail;
        _tail->prev = _head;
    }

    int get(int key) {
        if (!_cache.count(key)) return -1;
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = _cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!_cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            _cache[key] = node;
            addToHead(node);
            ++_size;
            if (_size > _capacity) {
                DLinkedNode* removed = removeNode(_tail->prev);
                _cache.erase(removed->key);
                --_size;
            }
        }
        else {
            DLinkedNode* node = _cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = _head;
        node->next = _head->next;
        _head->next->prev = node;
        _head->next = node;
    }

    DLinkedNode* removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

private:
    unordered_map<int, DLinkedNode*> _cache;
    DLinkedNode* _head;
    DLinkedNode* _tail;
    int _capacity;
    int _size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */