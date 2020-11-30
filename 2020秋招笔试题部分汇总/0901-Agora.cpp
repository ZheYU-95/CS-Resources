#include <iostream>
#include <cstring>   // strlen
#include <string>
using namespace std;

/* int main() {
    int a[] = {2, 4, 6, 8, 10, 1};
    cout << a << endl << 5[a] << endl << (1+3)[a] << endl << (a+1)[2] << endl;   // 0x61fef8 1 10 8
    return 0;
} */

/* int main(int ac, char **av) {
    int a = 0;
    // char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '\0'};
    char arr[] = "012345678";  // 这两种方式赋值效果一样，不过第二种省略'\0'，记得末尾是有的
    int c = 0;
    strncpy(arr, "array", 5);
    a = strlen(arr);
    c = sizeof(arr);
    cout << arr << endl << a << " " << c;    arrat5678  9  10
} */


/* struct MyStruct {
    int data[2];
    MyStruct(int x, int y) {data[0] = x; data[1] = y;}
    virtual void f() {}  // struct或class中定义的成员函数和构造和析构函数不占整体的空间。如果有虚函数的话，会有4个字节的地址存放虚函数表的地址
};  // 结构体占用内存大小要考虑到内存对齐问题

int main(int ac, char **av) {
    MyStruct a(10, 20);
    // MyStruct *pa = &a;  // 结构体a占用12B
    int *pa = (int *) &a;   // 使用C风格的类型转换，把结构体指针转化为整型指针
    cout << &pa[0] << " " << &pa[1] << " " << &pa[2] << endl;  // 0x61ff00 0x61ff04 0x61ff08
    cout << 1[pa] << " " << 2[pa] << endl;  // 10 20
    cout << sizeof(a) << endl;  // 12
    return 0;   
} */


/* int main(int ac, char **av) {
    int a = -1;
    unsigned int *ptrUInt = (unsigned int*)&a;
    int b = *(int*)ptrUInt;

    void *ptrVoid = &a;
    float *ptrFloat = (float*)ptrVoid;
    ptrVoid = ptrFloat;
    int c = *(int*)ptrVoid;

    cout << b << endl << c << endl;  // -1 -1
    return 0;
} */





/* 1. 给出一个单链表依次节点，判断是否有环路 */
/* 
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    ListNode *preHead = new ListNode(-1);
    ListNode *head = preHead;

    string str;
    getline(cin, str);
    for (char c : str) {
        if (!isdigit(c)) continue;
        int num = c - '0';
        head->next = new ListNode(num);
        head = head->next;
    }

    ListNode *slow = preHead;
    ListNode *fast = preHead;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast && slow->val == fast->val) {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
} */





/* 2. */

/* #include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int limit = INT_MAX/n;
    int m = 0, cnt = 0;
    for (int c = 1; c <= limit; ++c) {
        m = c*n;
        int tmp_cnt = 0;
        while (m) {
            if (!(m&1)) break;
            tmp_cnt++;
            m = m >> 1;
        }
        if (!m) {
            cnt = tmp_cnt;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
} */




/* #include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 0, cnt = 0;
    while(true) {
        int tmp_cnt = 0;
        int tmp_m = m, tmp_n = n;
        while (tmp_m || tmp_n) {
            if ((tmp_m&1)^(tmp_n&1)) {
                tmp_m = tmp_m >> 1;
                tmp_n = tmp_n >> 1;
                ++tmp_cnt;
            }
            else break;
        }
        if (!tmp_m && !tmp_n) {
            cnt = tmp_cnt;
            break;
        }
        m += n;
    }
    cout << cnt << endl;
    return 0;
} */