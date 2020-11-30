// Baidu-20200903

/* 1. 长为len走廊，两个人各自有想铺地毯的区间，二人共有n个想法，铺好后问每个位置铺了几块地毯，输出数组每个位置的地毯数 */
/* #include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int len, n;
        cin >> len >> n;
        vector<int> path(len, 0);
        for (int j = 0; j < n; ++j) {
            int l, r;
            cin >> l >> r;
            for (int k = l-1; k <= r-1; k++) path[k]++;
        }
        for (int num : path) cout << num << " ";
        cout << endl;
    }
    return 0;
} */










/* 2. 共有T组测试数据，每组里面有n个人，m个戏剧角色，每个人要求的最少的戏份值存入players数组，每个角色所能提供的戏份值存入roles中
每组测试数据输出一行，每个数表示每个人（按照一开始输入的数据顺序）所选的角色编号（数组下标号+1），若选不到合适的角色，返回-1 */

/* #include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<int> palyers(n, 0);
        multimap<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            palyers[i] = tmp;
            mp.insert({tmp, i});
        }
        vector<int> roles(m, 0);
        multimap<int, int> mr;
        for (int i = 0; i < m; ++i) {
            int tmp;
            cin >> tmp;
            roles[i] = tmp;
            mr.insert({tmp, i});
        }
        sort(palyers.begin(), palyers.end());
        sort(roles.begin(), roles.end());

        vector<int> arrangement(n, -1);
        int idx = 0;
        for (int cur : palyers) {
            auto itp = mp.find(cur);
            while (roles[idx] < cur) idx++;
            if (idx >= m) break;
            auto itr = mr.find(roles[idx]);
            arrangement[itp->second] = itr->second + 1;
            mp.erase(itp);
            mr.erase(itr);
            idx++;
        }
        
        for (int num : arrangement) cout << num << " ";
        cout << endl;
    }
    return 0;
}
 */







/* 3. n级台阶，每步跨最多m步最少1步，并且每步与之前两步走的台阶数不能相同，问有多少种不同做法，结果对1e9+7取余 */
// 之前两步的状态要被记录，加上台阶数，构造一个三维dp数组

#include <iostream>
#include <vector>
using namespace std;

static const int mod = 1e9+7;    // 1000000007
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(m + 1)));
    for (int i = 0; i <= min(n, m); ++i) dp[i][i][0] = 1;
    
    for (int hig = 0; hig <= n; ++hig) {
        int count = 0;
        for (int nxt = 0; nxt <= m; ++nxt) {
            for (int cur = 0; cur <= m; ++cur) {
                if (cur != nxt) {
                    for (int pre = 0; pre <= m; ++pre) {
                        if (pre != nxt && pre != cur && hig >= nxt + cur && hig - nxt >= cur + pre && dp[hig - nxt][cur][pre] != 0) {
                            dp[hig][nxt][cur] =(dp[hig][nxt][cur] + dp[hig - nxt][cur][pre]) % 1000000007;
                            count = (count + dp[hig - nxt][cur][pre]) % 1000000007;
                        }
                    }
                }
            }
        }
        if (hig == n) {
            if (n <= m) {
                count++;
            }
            cout << count;
        }
    }
    return 0;
}






/* 4. 牛牛有n张卡片，每张卡片要么是0，要么是5，牛牛能从中选出一些组成一些数字，现在牛牛想请你找出所有可能整除90的最大数字，若不存在，输出-1
输入描述：
第一行包含一个正整数n
接下来一行包括n个整数ai
1<=0<=10^3
ai = 0或ai= 5

输出描述
输出一个数字表示答案

示例
输入：
11
5 5 5 5 5 5 5 5 5 5 0
输出
5555555550
*/
// 思路：直接根据0和5的个数进行作答，整除90，则5的个数为9的倍数，且最后一位一定是0，接下来代码实现
