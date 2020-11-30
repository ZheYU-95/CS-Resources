// 美团2020.8.15笔试题

// 一个数的四倍 与 原数字构成逆序数，问这样的一堆在n的范围内有多少对，分别是？
// #include <iostream>
// #include <stack>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {
//     int n;
//     while (cin >> n) {
//         int res = 0;
//         vector<vector<int>> vec;
//         vec.push_back({});
//         for (int num = 1; num <= n; ++num) {
//             int rnum = 4*num;

//             string sNum = to_string(num);
//             string sRNum = to_string(rnum);
//             stack<char> stk;
//             for (char i : sNum) stk.push(i);
//             for (char j : sRNum) {
//                 if (j == stk.top()) stk.pop();
//                 else break;
//             }
//             if (stk.empty()) {
//                 res++;
//                 vec.back().push_back(num);
//                 vec.back().push_back(rnum);
//                 vec.push_back({});
//             }
//         }
//         cout << res << endl;
//         for (int i = 0; i < res; ++i) {
//             cout << vec[i][0] << " " << vec[i][1] << endl;
//         }
//     }
//     return 0;
// }



// 旅行问题：如果可以形成闭环即为有一段旅程：天津-上海，上海-天津即为一段，同城也算一段旅程，问一共有多少段旅程？输入第一行为车票数，输出旅行段数
// 6
// beijing tianjin
// tianjin shanghai
// shanghai tianjin
// tianjin shanghai
// shanghai shenyang
// shenyang beijing
// 输出：2

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;
// int main() {
//     int n;
//     while (cin >> n) {
//         vector<string> trip;
//         int cnt = 0;
//         for (int i = 0; i < n; ++i) {
//             string src, des;
//             cin >> src >> des;
//             if (trip.empty()) trip.push_back(src);
//             if (!trip.empty()) {
//                 auto it = find(trip.begin(), trip.end(), des);
//                 if (it != trip.end()) {
//                     cnt++;
//                     int len = trip.size();
//                     for (int i = it-trip.begin(); i < len; ++i) trip.pop_back();
//                 }
//                 else trip.push_back(des);
//             }
//         }
//         cout << cnt << endl;
//     }
//     return 0;
// }



// 一共输入n行，每行输入的两个数表示二者相连，求无向图中连通分量的个数（leetcode.323）
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 方法1：DFS
void dfs(vector<vector<int>>& graphs, int i, vector<bool>& visited) {
    if (visited[i]) return;
    else visited[i] = true;
    for (int j = 0; j < graphs[i].size(); ++j) {
        dfs(graphs, graphs[i][j], visited);
    }
}
int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> graphs(n);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            graphs[a-1].push_back(b-1);
            graphs[b-1].push_back(a-1);
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cnt++;
                dfs(graphs, i, visited);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


// 方法2：BFS
// int main() {
//     int n;
//     while (cin >> n) {
//         vector<vector<int>> graphs(n);
//         for (int i = 0; i < n; ++i) {
//             int a, b;
//             cin >> a >> b;
//             graphs[a-1].push_back(b-1);
//             graphs[b-1].push_back(a-1);
//         }
//         vector<bool> visited(n, false);
//         queue<int> q;
//         int cnt = 0;
//         for (int i = 0; i < n; ++i) {
//             if (visited[i]) continue;
//             else {
//                 q.push(i);
//                 ++cnt;
//             }
//             while (!q.empty()) {
//                 int tmp = q.front(); 
//                 q.pop();
//                 if(!visited[tmp]) {
//                     visited[tmp] = true;
//                 }
//                 else continue;
//                 for (int j = 0; j < graphs[tmp].size(); ++j) 
//                     if (!visited[graphs[tmp][j]]) q.push(graphs[tmp][j]);
//             }
//         }
//         cout << cnt << endl;


//     }
//     return 0;
// }


// 方法3：并查集
// https://blog.csdn.net/liujian20150808/article/details/50848646
// https://leetcode-cn.com/tag/union-find/
// int main() {
//     int n;
//     while (cin >> n) {
//         vector<vector<int>> graphs(n);
//         for (int i = 0; i < n; ++i) {
//             int a, b;
//             cin >> a >> b;
//             graphs[a-1].push_back(b-1);
//             graphs[b-1].push_back(a-1);
//         }
//     }
//     return 0;
// }



//有n辆车，两处各需要a,b辆车，下面n行输入表示每辆车去两处的收益，求如何调度车辆使得总收益最大？输出最大收益

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    while (cin >> n >> a >> b) {
        vector<vector<int>> vals;
        vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            vals.push_back({x, y});
            for (int j = min(a, i+1); j >= 0; --j) {
                for (int k = min(b, i+1-j); k >= 0; --k) {
                    if (j + k + (n-i) < a + b) break;
                    if (j > 0) dp[j][k] = max(dp[j][k], dp[j-1][k] + vals[i][0]);
                    if (k > 0) dp[j][k] = max(dp[j][k], dp[j][k-1] + vals[i][1]);
                }
            }
        }
        cout << dp[a][b] << endl; 
    }
}









// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n;
//     while (cin >> n) {
//         // cin.ignore();
//         string str[2*n];
//         for (int i = 0; i < n; ++i) {
//             cin >> str[2*i] >> str[2*i+1];
//             // getline(cin, str[i]);
//         }
//         for (int i = 0; i < 2*n; ++i) {
//             cout << str[i];
//         }
//     }
//     return 0;
// }