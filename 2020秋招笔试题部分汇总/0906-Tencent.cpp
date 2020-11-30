// Tencent-20200906

/* 1. 链表的公共部分：两个降序链表中均出现的子序列 */
/* #include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;
    ListNode* preHead1 = new ListNode(-1);
    ListNode* head1 = preHead1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        head1->next = new ListNode(x);
        head1 = head1->next;
    }

    int m;
    cin >> m;
    ListNode* preHead = new ListNode(-1);
    ListNode* head = preHead;
    ListNode* cur = preHead1->next;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        while (cur) {
            if (x == cur->val) {
                head->next = new ListNode(x);
                head = head->next;
                cur = cur->next;
                break;
            }
            else if (x < cur->val) {
                cur = cur->next;
            }
            else break;
        }
    }
    ListNode* cur2 = preHead->next;
    while (cur2) {
        cout << cur2->val << " ";
        cur2 = cur2->next;
    }

    return 0;
} */








/* 2. notice transmission：下达通知给编号为0的人，所有与他一个小团队的人都从他知道通知，以此类推
输入第一行两个数n(总共有n个人),m(个小团队)，接下来m行，每一行第一个数先输入一个x，代表这个小团队有x个人，后面跟着x个数，
代表这个小团队里面人的编号（0~n-1，一个人可能属于多个团队或都不属于），1<=n<=100000,1<=m<=500,1<=x<=100；输出一个整数表示知晓了通知的人数
50 5
2 1 2
5 10 11 12 13 14
2 0 1
2 49 2
4 6 7 8 2
 */

/* #include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> group(m);
    vector<vector<int>> staff(n);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int num;
            cin >> num;
            group[i].push_back(num);
            staff[num].push_back(i);
        }
    }
    
    vector<int> informed(n, 0);
    vector<int> informed_g(m, 0);
    informed[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < staff[cur].size(); ++j) {
                if (informed_g[staff[cur][j]]) continue;
                informed_g[staff[cur][j]] = 1;
                for (int k = 0; k < group[staff[cur][j]].size(); ++k) {
                    if (informed[group[staff[cur][j]][k]]) continue;
                    q.push(group[staff[cur][j]][k]);
                    informed[group[staff[cur][j]][k]] = 1;
                }
                
            }
        }
    }
    int cnt = 0;
    for (int num : informed) {
        cnt += num;
        // cout << num << " ";
    }
    cout << cnt << endl;
    
    return 0;
} */









/* 3.输入的第一行为两个整数N,K，接下来的N行每行一个字符串，1<=N，K<=1e5，保证K合法，字符串中只有数字和英文字母；
输出2*K行，每行有一个字符串和一个该字符串出现的次数，前面K行输出前K多，按照出现次数降序排列，若出现次数相同，按照字符串字典序较小的优先输出；
后面K行输出前K少，按照出现次数升序排列，若出现次数相同，按照字符串字典序较小的优先输出  */

/* #include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Less {
    operator()(pair<int, string>& p1, pair<int, string>& p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

struct Greater {
    operator()(pair<int, string>& p1, pair<int, string>& p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, string>> vecAsc;
    unordered_map<string, int> m;
    // map不能按值排序，只能按键排序或者把pair放到vector中
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        m[str]++;
    }
    for (auto& x : m) vecAsc.push_back(make_pair(x.second, x.first));
    vector<pair<int, string>> vecDesc(vecAsc);
    sort(vecAsc.begin(), vecAsc.end(), Less());   // 按照出现次数升序排，相同次数字典序升序
    sort(vecDesc.begin(), vecDesc.end(), Greater());  // 按照出现次数降序，相同次数字典序升序
    
    for (int i = 0; i < k; ++i) {
        cout << vecDesc[i].second << " " << vecDesc[i].first << endl;
    }
    for (int i = 0; i < k; ++i) {
        cout << vecAsc[i].second << " " << vecAsc[i].first << endl;
    }
    return 0;
} */







/* 4.第一行输入n(首歌)，第二行输入n个整数，代表每首歌的长度，第三行输入整数m，代表最多播放歌的分钟数，1<=n<=1000,1<=a[i],m<=1e5，调整n首歌的播放顺序，最多能听多少分钟，
若到m分钟有歌没播放完，会在它被播完后停止。输出最多听歌的分钟数 */

/* #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backTrack(vector<int>& songs, vector<int>& listened, vector<int>& res, int minutes, int idx, int m) {
    if (minutes >= m) {
        res.push_back(minutes);
        return;
    }
    int n = songs.size();
    listened[idx] = 1;
    for (int i = 0; i < n; ++i) {
        if (listened[i]) continue;
        if (minutes+songs[i] >= m) {
            int j = n - 1;
            while (listened[j]){j--;}
            backTrack(songs, listened, res, minutes+songs[j], j, m);
            break;
        }
        else backTrack(songs, listened, res, minutes+songs[i], i, m);
    }
    listened[idx] = 0;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> songs;
    for (int i = 0; i < n; ++i) {
        int dur;
        cin >> dur;
        songs.push_back(dur);
    }
    int m;
    cin >> m;
    sort(songs.begin(), songs.end());
    vector<int> listened(n, 0);
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        backTrack(songs, listened, res, songs[i], i, m);
    }
    cout << *max_element(res.begin(), res.end()) << endl;
    
    return 0;
} */






/* 5.构造一个长度为n的数列A，使得对于任意在[1,m]范围内的两个不相等整数x,y都存在数列中的某个下标p，使得A_p=x, A_(p+1)=y或者A_p=y, A_(p+1)=x，给定长度n，问最大的m是多少
输入第一行T表示组数，随后T行每行一个整数n；输出一行一个数字表示最大的m */








/* 6. 黑白棋,每次可以互换相邻的棋子,求使得每种颜色棋子递增排序的最小交换次数 */
// https://atcoder.jp/contests/arc097/tasks/arc097_c

#include<iostream>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 4000 + 5;
int dp[maxn][maxn];
int costB[maxn][maxn];
int costR[maxn][maxn];
int id[maxn * 2]; //棋子的编号
int n;
string str;
map<int, int> posB, posR;
void pre_cost() //初始化costB，costR
{
    //costB[i][1~n] 在第i个棋子前面 编号为1~n黑棋子的出现次数
    //costR[i][1~n] 在第i个棋子前面 编号为1~n白棋子的出现次数
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < i; j++)
        { //costB[i][j] 在第i个棋子前面 id为j的黑棋子个数
            int index = id[j];
            if (str[j] == 'B')
            {
                costB[i][index]++;
            }
            else
            {
                costR[i][index]++;
            }
        }
    }
    //对costB[i][1~n]，costA[i][1~n]做前缀和后
    //costB[i][j]代表，第i个棋子前面，编号<=j的黑棋子个数
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            costR[i][j] += costR[i][j - 1];

            costB[i][j] += costB[i][j - 1];
        }
    }
}
int cost_B(int i, int j)
{ //加入第i个黑棋，且1~j个白棋已经排好序的代价
    int Cost = 0;
    int pos = posB[i];
    //计算 pos 位置前，值大于i的黑棋，值大于j的白棋的数量
    Cost = pos - (costB[pos][i] + costR[pos][j]);
    return Cost;
}
int cost_R(int i, int j)
{ //加入第i个白棋，且1~j个白棋已经排好序的代价
    int Cost = 0;
    int pos = posR[i];
    //计算 pos 位置前，值大于i的白棋，值大于j的黑棋的数量
    Cost = pos - (costR[pos][i] + costB[pos][j]);
    return Cost;
}

void init()
{
    cin >> n;

    cin >> str;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> id[i];
        if (str[i] == 'B')
        {
            posB[id[i]] = i;
        }
        else
        {
            posR[id[i]] = i;
        }
    }
}
void init1(){
    cin>>n;
    str="";
    for(int i=0;i<2*n;i++){
        char ch;
        cin>>ch;
        cin>>id[i];
        str+=ch;
        
        if(str[i]=='B'){
            posB[id[i]]=i;
        }
        else{
            posR[id[i]]=i;
        }
    }
   // cout<<str;
}
/*
4
BWBWBWBW

*/
int main()
{
    init1();
    //cout<<n<<endl;
    pre_cost();
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    // dp[1][0]=cost_B(1,0);
    // dp[0][1]=cost_R(1,0);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // if (i == j && i == 0)
            // {
            //     continue;
            // }
            if(i-1>=0){
                dp[i][j] = min(dp[i - 1][j] + cost_B(i, j), dp[i][j]);
            }
            if(j-1>=0){
                dp[i][j] = min(dp[i][j] , dp[i][j - 1] + cost_R(j, i));
            }
            //
            //dp[i][j] = min(dp[i - 1][j] + cost_B(i, j), dp[i][j - 1] + cost_R(j, i));
           // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
        }
    }
    cout << dp[n][n];

    return 0;
}
