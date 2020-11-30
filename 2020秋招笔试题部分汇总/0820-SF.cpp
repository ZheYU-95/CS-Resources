/*
 * @Author: your name
 * @Date: 2020-08-20 20:36:25
 * @LastEditTime: 2020-09-10 14:21:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\0820-SF.cpp
 */

/* 小A现在有n个空闲的服务器，第 i 个服务器拥有ai的带宽。有m个客户来租服务器，第 i 位客户需要带宽至少为bi的服务器，并且愿意花ci元作为预算。
（服务器带宽独立不可叠加，若不能成功租出则输出0） 小A可以选择拒绝一些人，现在，小A想知道自己的服务器最多能租多少钱？ 
输入第一行包含两个数n,m 接下来1行n个数，第i个数ai代表第 i 个服务器的带宽大小。接下来m行，每行两个数bi,ci，代表客户需求的带宽大小和他的预算。
n,m≤1000 , 1≤ai,bi,ci≤1000*/

/* #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> servers(n, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            servers[i] = a;
        }
        vector<vector<int>> clients(m, vector<int>(2, 0));
        for (int i = 0; i < m; ++i) {
            int b, c;
            cin >> b >> c;
            clients[i][0] = b;
            clients[i][1] = c;
        }
        sort(servers.begin(), servers.end());
        vector<bool> satisfied(m, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int max_price = 0, idx = -1;
            for (int j = 0; j < m; ++j) {
                if (servers[i] < clients[j][0] || satisfied[j]) continue;
                else {
                    if (max_price < clients[j][1]) {
                        max_price = clients[j][1];
                        idx = j;
                    }
                }
            }
            if (idx < 0) continue;
            satisfied[idx] = true;
            res += max_price;
        }
        cout << res << endl;
    }
    return 0;
} */


/* 2. 具体来说就是有n个任务，每个任务用l, r, w来表示任务开始的时间l，结束的时间r和完成任务获得的金钱。
克里森是个贪心的人，他想知道自己在任务不冲突的情况下最多获得多少金钱。
第一行一个数n表示任务的个数。(1≤n≤1e3) 接下来n行每行三个整数l, r, w表示第i个任务的开始时间，结束时间，以及收益。(1≤l≤r≤1e6,1≤w≤1e9) */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct Less {
    operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        tasks[i][0] = l;
        tasks[i][1] = r;
        tasks[i][2] = w;
    }
    sort(tasks.begin(), tasks.end(), Less());   // 对结束时间升序排列
    vector<int> dp(n+1, 0); // 做完第i个任务的收益
    dp[1] = tasks[0][2];
    for (int i = 2; i < n+1; ++i) {
        int idx = 0;
        for (int j = i-1; j >= 0; --j) {
            // 计算对于当前任务，最近可以完成的上一个任务的下标是什么
            // 即之前任务结束时间小于等于当前任务开始时间
            // 求对于选择做当前任务，再加上前一个可以做的任务的最大收益，返回dp[j]+task[i][2]
            if (task[j-1][1] <= task[i-1][0]) {
                idx = j;
                break;
            }
        }
        dp[i] = max(dp[i-1], dp[idx]+tasks[i-1][2]);
    }
    cout << dp[n] << endl;
    return 0;
}

