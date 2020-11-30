/*
 * @Author: 于哲
 * @Date: 2020-10-15 11:53:55
 * @LastEditTime: 2020-10-15 18:29:44
 * @LastEditors: Please set LastEditors
 * @Description: 2020-10-15 深信服笔试
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\1015-ShenXinFu.cpp
 */

/* 1.一个10*10的矩形棋盘，上面有两色棋子若干。
现在用一个10*10的数组A表示棋盘布局，数组每个元素表示一个棋盘位置，如果元素值为1表示该位置有黑色棋子，为2表示该位置有白色棋子，为0表示该位置没有棋子。
棋子有两种运动方式，分别叫“移动”，“跳动”。移动，即沿着十字形的四个直线方向，移动一步，只要目标位置没有棋子即可。跳动，即沿着十字形的四个直线方向，跳动2*n步，其中n为正整数。
跳动必须满足以下两点要求：1. 目标位置没有棋子；2. 跳动的起始位置，和目标位置之间，有且仅有一个棋子(任意一种颜色皆可)，且该棋子位于两个位置之间的中心点；
比如：假设某条直线上有9个位置，用这个串来表示：'a000b000c'，从a位置到c位置中间是b位置，如果除了a、b两个位置上有棋子外，其它七个位置都没棋子，则a位置的棋子允许跳动到c位置。
移动方式必须单独使用，每次只能移动一步。跳动方式允许连跳，连跳过程还允许变换方向。
连跳，即每次跳动后，如果在四个直线方向上，能找到下一个满足跳动规则的位置，则允许把任意多次跳动合成一次完成。
已知一个棋盘布局，请计算指定颜色棋子的最远运动距离。所谓运动距离，指当棋子只采用移动方式运动时，需要移动的最少步数，也即横向距离和纵向距离之和。
比如，假设棋盘布局如下，每个数字和字母表示一个位置，如果为0表示该位置没有棋子，为1或2表示有棋子，b位置处也没有棋子。
按照规则，a位置处的棋子能直接一次跳到b位置，跳动的运动距离为：16。
a000000000
0000000000
1000000000
0000000000
0000000000
2000000000
0000000000
1000000000
00020001b0
0000000000 

input: 第一行为两个整数 X Y，分别为起始位置的X坐标和Y坐标。从第二行开始共有10行数据，每行数据为10个数字，每个数字三个取值：0(无棋子),1(黑棋),2(白棋)。
注：X,Y代表第Y行，第X列的数据位置，X，Y的取值范围为0-9。数据保证(X,Y)处一定有棋子。
output: 一个整数，表示(X,Y)处棋子的最远跳动距离。

0 0
1000000000
0000000000
1000000000
0000000000
0000000000
2000000000
0000000000
1000000000
0002000100
0000000000

16
 */

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <queue>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> graph(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int movement = 1;
    int jump = 0;
    // set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto cur = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j) {
                for (int k = 1; k < 5; ++k) {
                    int mid_x = cur.first + k * dirs[j][0];
                    int mid_y = cur.second + k * dirs[j][1];
                    if (mid_x < 0 || mid_y < 0 || mid_x > 9 || mid_y > 9) break;
                    if (graph[mid_x][mid_y] == 0  /* || visited.count({mid_x, mid_y}) */ ) continue;
                    
                    // visited.insert({mid_x, mid_y});
                    int nxt_x = cur.first + 2 * k * dirs[j][0];
                    int nxt_y = cur.second + 2 * k * dirs[j][1];
                    if (nxt_x < 0 || nxt_y < 0 || nxt_x > 9 || nxt_y > 9) break;
                    q.push({nxt_x, nxt_y});
                    jump = max(jump, abs(nxt_x - x) + abs(nxt_y - y));
                }
            }
        }
    }
    cout << max(jump, movement) << endl;
    return 0;
} 




/* 2.田忌用孙膑的策略赢了齐威王后，齐威王识破了孙膑的计策，于是增加了比赛规则：
1、每人用N匹马参赛。这N匹马，速度最快的称为1等马，次快的称为2等马，依此类推；2、齐威王可以决定自己每匹马的出场顺序；3、田忌每次出场的马必须与齐威王的马等级相同。
例如，第5场齐威王选择了7等马，则田忌也必须用7等马参加第5场。
田忌给自己的马都编了号，编号为1到N。编号顺序是随机的，与马的等级或速度无关。
现在已知齐威王每匹马的出场顺序，那么，田忌的马应该按什么样的顺序出场呢？

输入描述: 第一行为一个整数T，表示测试数据的组数（T<=100）。接下来是各组测试数据。每组测试数据占三行：
第一行为一个正整数N（N<=1000），表示每人用N匹马参赛；
第二行为N个互不相同的正整数Ai（Ai<=2000000000），依次表示齐威王每次出场的马的速度。例如，A3为785，表示齐威王第3场选择了速度为785的马参加比赛；
第三行为N个互不相同的正整数Bi（Bi<=2000000000），依次表示田忌每匹马的速度。例如，B3为785，表示田忌的3号马速度为785。

输出描述:
每组测试数据输出一行，为N个正整数Ci，依次表示田忌每次出场的马的编号。例如C3为7，表示田忌应该用7号马参加第3场比赛。
整数之间用空格隔开，行尾不能有多余的空格。
4
5
12 89 34 66 20
67 16 24 95 42
3
1 2 3
6 5 4
7
6 1 7 2 9 4 5
6 1 7 2 9 4 5
4
8 6 5 7
5 6 7 8


2 4 5 1 3
3 2 1
1 2 3 4 5 6 7
4 2 1 3 */


/* #include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<vector<int>> res(T);
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<pair<int, int>> a;
        vector<pair<int, int>> b;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            a.push_back({tmp, i});
        }
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            b.push_back({tmp, i});
        }
        vector<int> sequence(n);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            int idx_a = a[i].second;
            int idx_b = b[i].second;
            sequence[idx_a] = idx_b+1;
        }
        res[t] = sequence;
    }
    for (int t = 0; t < T; ++t) {
        for (int i = 0; i < res[t].size()-1; ++i) {
            cout << res[t][i] << " ";
        }
        cout << res[t][res[t].size()-1] << endl;
    }
    
    return 0;
} */