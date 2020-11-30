// 大疆2020.08.16

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm> // min
#include <climits>  // INT_MAX

using namespace std;


// 1.有向图的最短路径
/* 第一行输入两个个正整数 N和 P，其中N表示路标的数量， P表示通道的数量。 (1 < N <= 200,  0 <= P <= N * (N - 1) / 2 ）
接下来的P行，每行输入三个正整数 A, B, T，A表示起点路标的编号，B表示终点路标的编号，T表示路标A到路标B需要时间T。 (0 <= A, B <= N-1, 1 <= T <= 100)
最后一行输入一个正整数 X，表示裁判给出的终点路标编号 (0 =< X <= N)
输出描述
输出一个正整数，表示小车从0号路标到X号路标之间移动的最短用时 */

/* int main() {
    int n, p;
    while (cin >> n >> p) {
        vector<vector<int>> paths(n, vector<int>(n, -1));
        for (int i = 0; i < p; ++i) {
            int a, b, t;
            cin >> a >> b >> t;
            paths[a][b] = t;
        }
        int x;
        cin >> x;  // start from 0, ends at x
        vector<int> costs(n, INT_MAX);
        queue<int> q;
        q.push(0);
        costs[0] = 0;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            if (tmp == x) continue;
            for (int i = 0; i < n; ++i) {
                if (paths[tmp][i] != -1) {
                    costs[i] = min(costs[i], costs[tmp] + paths[tmp][i]);
                    q.push(i);
                }
            }
        }
        cout << costs[x] << endl;
    }
    return 0;
} */



// 2. 动态规划(0-1背包问题)
/* 第一行输入两个整数N和X，中间用空格隔开，其中N表示游戏的数目N(1<=N<=10)，X表示计划玩游戏的总时间天数 (1<=X<=1000)。
接下来每行输入第i个游戏的成就值Ai(0<=Ai<=10000) 和 通关所需要花费时间Bi天 (1<=Bi<=500) 中间用空格隔开。(1<=i<=N)
输出描述 可以达到成就之和的最大值。 */

/* int main() {
    int n, x;
    while (cin >> n >> x) {
        vector<int> dp(x+1, 0);
        // vector<int> games;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            // games.push_back({a, b});
            for (int j = 0; j + b <= x; ++j) {
                dp[j+b] = max(dp[j+b], dp[j]+a);
            }
        }
        cout << dp[x] << endl;
    }
    return 0;
} */



// 3. 贪心算法：每回删除后都只保留最小的字符串
/* 给定一个非负的、字符串形式的整形数字，例如“12353789”，字符串的长度也就是整形数字的位数不超过10000位，
并且字符串不会以0开头，挑选出其中K个数字（K小于字符串的长度）并删掉他们，使得剩余字符组成新的整数是最小的。
输入描述：第一行输入一串纯数字形式的字符串，组成一个正整数；第二行输入一个正整数K (K < 字符串的长度)
输出描述：输出一个数字（字符串格式） */

string deleteCharToMinStr(string s) {
    string res = s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        string tmp = s;
        tmp.erase(tmp.begin()+i);
        res = min(res, tmp);
    }
    return res;
}

int main() {
    string str;
    while (cin >> str) {
        int k;
        cin >> k;
        string res = str;
        for (int i = 0; i < k; ++i) {
            res = deleteCharToMinStr(res);
        }
        while (res[0] == '0') res.erase(res.begin());  // res[0]是"，因为输入时"*****", 直接输入*****可以避免该情况
        if (res.empty()) cout << "0" << endl;
        else cout << res << endl;
    }
    return 0;
}