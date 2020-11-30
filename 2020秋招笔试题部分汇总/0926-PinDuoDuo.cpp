/*
 * @Author: 于哲
 * @Date: 2020-09-26 12:30:35
 * @LastEditTime: 2020-10-09 10:58:25
 * @LastEditors: Please set LastEditors
 * @Description: 拼多多笔试
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\0926-PinDuoDuo.cpp
 */


/* 1. 已知0-9这十个数的各自的10*10矩阵，每个矩阵由0/1组成，1的形状围成对应数字。输入T组数据，每组数据中第一行位该矩阵的行/列数n，要求矩阵n*n，且n为10的整数倍
接下来n行每行输入n个数。输出每组数据中输入矩阵所代表的那个数字。保证每个矩阵的输入都是正确的且都能找到原本的对应数字。
2
10
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 1 1 0 0 1 1 0 0
0 0 1 1 0 0 1 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/


/* #include <iostream>
#include <vector>
using namespace std;

int cnt(const vector<int>& row) {
    int c = 0;
    for (int num : row) c += num;
    return c;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        vector<vector<int>> pattern(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                int tmp;
                cin >> tmp;
                pattern[j][k] = tmp;
            }
        }
        int coef = n/10;
        vector<vector<int>> smaller(10, vector<int>(10));
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                smaller[j][k] = pattern[coef*j][coef*k];
            }
        }
        int num_1 = cnt(smaller[1]);
        if (num_1 == 6) res[i] = 7;
        else if (num_1 == 2) {
            int num_7 = cnt(smaller[7]);
            if (num_7 == 2) res[i] = 4;
            else {
                if (smaller[1][2] == 1) res[i] = 5;
                else res[i] = 1;
            }
        }
        else {
            int num_2 = cnt(smaller[2]);
            if (num_2 == 2) res[i] = 6;
            else if (num_2 == 6) res[i] = 2;
            else {
                int num_6 = cnt(smaller[6]);
                if (num_6 == 2) res[i] = 9;
                else {
                    if (smaller[3][2] == 0) res[i] = 3;
                    else if (smaller[4][4] == 0) res[i] = 0;
                    else res[i] = 8;
                }
            }
        }
    }
    for (int x : res) cout << x << endl;
    return 0;
} */









/* 2. 迷宫：从T位置出发，找到最近的X，输出最近的距离，并输出它的坐标，若有多个相距相同的，输出他们的坐标。其中为1的位置表示不能经过，如果不存在这样的路径输出0
5 6
X00100
00000X
01T000
0X1010
00000X

4
0 0 1 5
 */

/* #include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> positions;
    pair<int, int> target;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char tmp;
            cin >> tmp;
            graph[i][j] = tmp;
            if (tmp == 'T') target = {i, j};
        }
    }
    queue<pair<int, int>> q;
    q.push(target);
    visited[target.first][target.second] = 1;
    int dirs[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    int cnt = 0;

    while (!q.empty()) {
        cnt++;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto cur = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j) {
                int x = cur.first + dirs[j][0];
                int y = cur.second + dirs[j][1];
                if (x < 0 || x >= n || y < 0 || y >= m || graph[x][y] == '1' || visited[x][y]) continue;
                if (graph[x][y] == 'X') positions.push_back({x, y});
                else q.push({x, y});
                visited[x][y] = 1;
            }
        }
        if (!positions.empty()) break;
    }
    if (positions.empty()) {
        cout << 0;
        return 0;
    }
    sort(positions.begin(), positions.end());
    cout << cnt << endl;
    for (auto& arr : positions) cout << arr[0] << " " << arr[1] << " ";
    
    return 0;
}
 */







// https://www.nowcoder.com/discuss/526736
/* 3.n个人中选k个人参赛，要求最后选出的组合能力值最大。n人中有n-1对互斥关系，保证队伍中不存在有互斥关系的两个人，选不出k个人输出-1
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

/*
dp[n][k][2]:
    dp[i][j][t]表示以i节点为根的子树下，选择j个点，其中包括i节点(t=1)/不包括i节点(t=0)能取到的最大权值和，以节点1为根做树形背包，max(dp[1][k][0],dp[1][k][1])即为答案。转移参考背包。
*/
const int N = 1 << 14;
const int K = 1 << 7;
vector<int>G[N];
int a[N],dp[N][K][2],sz[N];
int n,k;
void dfs(int u,int p) {
    sz[u] = 1;
    vector<int> son;
    son.push_back(0);
    for(int&v : G[u]) {
        if(v == p) continue;
        son.pb(v);
    }
    int z = son.size()-1;
    vector<vector<int>> f(z+1,vector<int>(k+1,-1));    //f[i][j]表示前i个儿子取j个最大权值和，其中只对不选儿子的情况进行背包，因为要用来转移到dp[u][i][1]。
    vector<vector<int>> g(z+1,vector<int>(k+1,-1));    //g[i][j]表示前i个儿子取j个最大权值和，不限制是否选择儿子。
    f[0][0] = g[0][0] = 0;
    for(int i = 1; i <= z; ++i) {
        int v = son[i];
        dfs(v,u);
        for(int j = 0; j <= sz[v]; ++j)
            if(~dp[v][j][0])
                for(int o = k; o >= j; --o)
                    if(~f[i-1][o-j])
                        f[i][o] = max(f[i][o], f[i-1][o-j] + dp[v][j][0]);
        for(int j = 0; j <= sz[v]; ++j)
            for(int o = 0; o < 2; ++o)
                if(~dp[v][j][o])
                    for(int l = k; l >= j; --l)
                        if(~g[i-1][l-j])
                            g[i][l] = max(g[i][l], g[i-1][l-j] + dp[v][j][o]);
        sz[u] += sz[v];
    }
    for(int i = 0; i <= k; ++i)
        dp[u][i][0] = g[z][i];
    for(int i = 1; i <= k; ++i)
        if(~f[z][i-1]) {
            dp[u][i-1][0] = max(f[z][i-1], dp[u][i-1][0]);
            dp[u][i][1] = f[z][i-1] + a[u];
        }
}
int main() {
    int QAQ;
    cin >> QAQ;
    while(QAQ--) {
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) cin>>a[i];
        for(int i = 1,u,v; i < n; ++i) {
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1,0);
        cout << max(dp[1][k][0], dp[1][k][1]) << endl;
    }
}






/* 4.n行m列的道路，1<=n<=10^9,1<=m<=5，有两种规格的瓷砖分别是1×1和2×2，问多少种方案铺满道路，答案对10^9+7取模。
本质上是求有多少种放2×2的方案，因为只要放完2×2，剩下的全放1×1就行。注意到m很小，可以对m状态压缩，用一个数字x表示当前状态，如果x的二进制表示第i位为1，那么该状态的第i个位置有瓷砖。
例如15=1111，那么当前行全部铺满了，要注意有些状态不合法，比如13=1101,9=1001，原因是现在只铺2×2的瓷砖，那么1的个数必须为偶数，且要能划分为若干个连续的11，
下面用legal∈{0,1}表示状态i是否合法，可以简单预处理出来。
然后用dp来解决这个问题。显然，如果n=1 or m=1，那只有一种方案，因为放不下2×2，否则我们用dp[i][j]来表示在第i行，且第i行状态为j的方案数。
*/

#include <iostream>
#include 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
const int M=5;
const int K=1<<M;
const int mod=1000000007;
bool o[K];            //legal[K]
bool ok(int x)        //检查状态x是否合法
{
    int c=__builtin_popcount(x);
    if(c&1) return 0;
    for(int i=0;i<M;++i)
    {
        if(!((x>>i)&1)) continue;
        if(i==M-1) return 0;
        if(!((x>>(i+1))&1)) return 0;
        ++i;
    }
    return 1;
}
bool ok(int x,int y)    //判断y是否能从x转移过来。
{
    if(!o[x]||!o[y]) return 0;
    return (x&y)==0;
}
string s(int x){string ret;if(!x) return "0";while(x)ret+='0'|(x&1),x>>=1;return ret;}                    //调试输出用。
void add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
int mul(const int&x,const int&y){return 1LL*x*y%mod;}
struct Mat
{
    int n;
    int a[K][K];
    Mat(){for(int i=0;i<K;++i)a[i][i]=1;}
    Mat(int z)
    {
        memset(a,0,sizeof(a));
        if(z==0) return;
        n=z;
        for(int i=0;i<n;++i)    //初始化为单位矩阵
            a[i][i]=1;
    }
    Mat operator*(Mat w)    //矩阵乘法
    {
        Mat ret(0);
        ret.n=n;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                for(int k=0;k<n;++k)
                    add(ret.a[i][j],mul(a[i][k],w.a[k][j]));
        return ret;
    }
    void output()
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cout<<a[i][j]<<" \n"[j==n-1];
        cout<<endl;
    }
};
Mat qp(Mat A,int b,int n)    //矩阵快速幂。
{
    Mat ret(n);
    for(;b;b>>=1,A=A*A)
        if(b&1) ret=ret*A;
    return ret;
}
int main()
{
    int n,m;cin>>n>>m;
    if(min(n,m)==1) return cout<<1<<endl,0;
    for(int i=0;i<K;++i)
        o[i]=ok(i);
    int k=1<<m;
    Mat A(k);
    for(int i=0;i<k;++i)
        for(int j=0;j<k;++j)
            A.a[i][j]=ok(i,j);        //矩阵A初始化
    A=qp(A,n-1,k);                    //A=A^(n-1)
    int ans=0;
    for(int i=0;i<k;++i)
        add(ans,A.a[i][0]);            //A第一行/第一列的和即为答案
    cout<<ans<<endl;
}







