/*
 * @Author: Yu Zhe
 * @Date: 2020-10-10 13:22:41
 * @LastEditTime: 2020-10-10 19:40:39
 * @LastEditors: Please set LastEditors
 * @Description: 2020-1010 vivo笔试
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\1010-ViVo.cpp
 */


/* 1.已知在某测试实验室，需要把 M 台手机连接到 N 个 WiFi 热点上，允许有的 WiFi 热点空置不用，请计算共有多少种连接方法？ */
/* #include <iostream>
#include <vector>
using namespace std;

int connect(int m, int n) {
    
}

int main() {
    
    return 0;
} */


/* 2.现在假设某培训项目有 n 个员工参加，已知每个员工到培训中心A和培训中心B的距离，请你帮助确定该培训项目的员工分配方案，
使得所有员工到培训中心的合计距离最短，且 A培训中心和 B培训中心的人数之差不能超过 1 。 
第一行输入为一个正整数，表示员工人数 n；
第二行开始起共有 n 行，每一行输入为空格间隔的两个正整数，分别表示该行的员工到培训中心A和培训中心B的距离。
输出为一个正整数，表示该项目的所有员工到达培训中心的合计最短距离。
4
10 20
30 200
50 70
20 25

125
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> distance(n, vector<int>(2));
    vector<int> d_a;
    vector<int> d_b;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        distance[i][0] = a;
        distance[i][1] = b;
        if (a < b) {
            d_a.push_back(i);
            res += a;
        }
        else {
            d_b.push_back(i);
            res += b;
        }
    }
    int num = n/2;
    int diff;
    d_a.size() > d_b.size()? diff = (d_a.size() - d_b.size())/2 : diff = (d_b.size() - d_a.size())/2;
    if (diff < 1) {
        cout << res << endl;
        return 0;
    }
    priority_queue<int, vector<int>, less<int>> pq;
    if (d_a.size() > d_b.size()) {
        for (int i = 0; i < d_a.size(); ++i) {
            int idx = d_a[i];
            int val = distance[idx][1] - distance[idx][0];
            if (pq.size() < diff) pq.push(val);
            else {
                if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
    }
    else {
        for (int i = 0; i < d_b.size(); ++i) {
            int idx = d_b[i];
            int val = distance[idx][1] - distance[idx][0];
            if (pq.size() < diff) pq.push(val);
            else {
                if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
    }
    while (!pq.empty()) {
        res += pq.top();
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << res << endl;

    return 0;
}







/* 3.迷宫地图 */

/* int solution(vector<vector<char> >& input) {
    int m = input.size(), n = input[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    pair<int, int> start, target;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (input[i][j] == '2') start = make_pair(i, j);
            else if (input[i][j] == '3') target = make_pair(i, j);
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    unordered_set<char> s;
    if (input[start.first][start.second] >= 'a' && input[start.first][start.second] <= 'z') s.insert(input[start.first][start.second]);
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int steps = 0;
    while (!q.empty()) {
        int len = q.size();
        steps++;
        for (int i = 0; i < len; ++i) {
            auto cur = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j) {
                int x = cur.first + dirs[j][0];
                int y = cur.second + dirs[j][1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                char c = input[x][y];
                if (c >= 'A' && c <= 'Z' && !s.count('a'+c-'A')) continue;
                if (c == input[target.first][target.second]) return steps;
                q.push({x, y});
                visited[x][y] = 1;
            }
        }
    }
    return -1;
} */