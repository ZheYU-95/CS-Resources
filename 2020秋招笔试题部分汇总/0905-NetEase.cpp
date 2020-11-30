// 网易-20200905

/* 1. 输入：第一行：n个货物槽，m个操作人数；第二行：n个整数表示各个货物槽1-N的货物单价；
接下来m块为每个人的操作，每一块每个人：第一行Ki表示操作次数，接下来Ki行每行为一次操作，
每次操作分"left"/"right", "take"/"retrun"/"keep", 如果不是keep还要后面一个数字i表示从第i个货物槽(1<=i<=N)拿走/送回货物，keep表示把某只手里的货物放进背包
每个人操作完后，货物柜不会重置，下一个人在此基础上继续操作，默认take时那个手是空的，return时那个手有货物，货物柜不会慢，也不会拿空
输出：每行一个整数，表示每个人操作完成后，手里+背包里所有货物的总价格 */
/* #include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<stack<int>> price(n);   // 每个货物槽为一个栈，最开始的货价入栈，后面放入的依次压入栈，再取时依次弹出，若栈size为1表示全是原本的无限量的货物，此时就不弹出栈了
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        price[i].push(tmp);
    }
    vector<int> ans(m, 0);
    for (int i =0; i < m; ++i) {
        int price_h[2] = {0 ,0};
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string hand, oper;
            cin >> hand >> oper;

            int lr = 0;
            if (hand == "left") lr = 0;
            else lr = 1;

            if (oper == "keep") {
                ans[i] += price_h[lr];
                price_h[lr] = 0;
                continue;
            }
            else {
                int num;
                cin >> num;
                if (oper == "take") {
                    price_h[lr] = price[num-1].top();
                    if (price[num-1].size() > 1) price[num-1].pop();
                }
                else {
                    price[num-1].push(price_h[lr]);
                    price_h[lr] = 0;
                }
            }
        }
        ans[i] += price_h[0]+price_h[1];
    }
    for (int pr : ans) cout << pr << endl;

    return 0;
} */







/* 2. 输入：第一行T，接下来T组，每组：第一行：W(每行字符数)，H(H行记录)；接下来H行每行W个字符表示背景内容；行和列从1开始计数
之后一行：P(列), Q(行)表示主角大小；之后Q行，每行P个字符，表示主角内容；最后一行输入i, j, a, b。i,j表示主角图像左上角字符所在的初始行列（范围从0开始）；a,b表示每帧移动速度
-100 <= i,j,a,b <= 100。有一个接口，每次调用只能修改某个位置的字符，问对每组数据从背景内容直至主角完全移出屏幕，调用接口的总次数
1
4 4
....
....
....
....
3 3
\o/
-|-
/.\
0 0 1 1
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> ans(T, 0);
    for (int t = 0; t < T; ++t) {
        int W, H;
        cin >> W >> H;
        vector<vector<char>> graph(H, vector<char>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                char ch;
                cin >> ch;
                graph[i][j] = ch;
            }
        }

        int P, Q;
        cin >> P >> Q;
        vector<vector<char>> role(Q, vector<char>(P));
        for (int i = 0; i < Q; ++i) {
            for (int j = 0; j < P; ++j) {
                char ch;
                cin >> ch;
                role[i][j] = ch;
            }
        }
        vector<vector<char>> frame(graph);
        
        int i, j, a, b;
        cin >> i >> j >> a >> b;

        int cnt = 0, nconsider = 0;
        while (nconsider < Q*P) {
            nconsider = 0;
            for (int q = 0; q < Q; q++) {
                for (int p = 0; p < P; ++p) {
                    int x = q + i - 1;
                    int y = p + j - 1;
                    if (x < 0 || y < 0 || x >= H || y >= W) {
                        nconsider++;
                        continue;
                    }
                    if (frame[x][y] == role[q][p]) continue;
                    frame[x][y] = role[q][p];
                    cnt++;
                }
            }
            
            // 复原人物上一步出现过的地方的背景
            for (int h = 0; h < H; ++h) {
                for (int w = 0; w < W; ++w) {
                    if (h >=i-1 && h<i+Q-1 && w>=j-1 && w<j+P-1) continue;
                    frame[h][w] = graph[h][w];
                }
            }
            i += a;
            j += b;
            // for (int h = 0; h < H; ++h) {
            //     cout << endl;
            //     for (int w = 0; w < W; ++w) {
            //         cout << frame[h][w];
            //     }
            // }
            // cout << cnt << endl;
        }
        ans[t] = cnt;
    }
    for (int num : ans) cout << num << endl;

    return 0;
}











/* 3. maze 
输入：T组数据，每组数据有N行，每行两个整数X(0向上, 1向下, 2向左, 3向右), Y(-1:不能成功移动, 1:成功移动)，不能成功移动表示现在位置向该方向移动一格不能完成
默认最后一行一定是Y=1，表示第一次到达终点出口，输出：每行一个整数，表示每组数据中根据给出的移动方向及其状态判断从起点到终点的最少操作数 */
/* #include <iostream>
#include <set>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> ans(T, 0);
    for (int  t = 0; t < T; ++t) {
        set<pair<int, int> > graph;
        pair<int, int> terminal;
        int n;
        cin >> n;
        int  x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            int dir, res;
            cin >> dir >> res;
            if (res == -1) continue;
            if (dir == 0) y++;
            else if (dir == 1) y--;
            else if (dir == 2) x--;
            else if (dir == 3) x++;
            graph.insert({x, y});
            if (i == n-1) terminal = {x, y};
        }
        // cout << "terminal" << terminal.first << " " << terminal.second << endl;
        int step = 0;
        bool flag = false;
        queue<pair<int, int> > q;
        pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        q.push({0, 0});
        graph.erase(q.front());
        while (!q.empty()) {
            int len = q.size();
            step++;
            for (int i = 0; i < len; ++i) {
                int prev_x = q.front().first;
                int prev_y = q.front().second;
                // cout << prev_x << "+" << prev_y << " ";
                if (prev_x == terminal.first && prev_y == terminal.second) {
                    flag = true;
                    break;
                }
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int cur_x = prev_x + dirs[j].first;
                    int cur_y = prev_y + dirs[j].second;
                    if (graph.count({cur_x, cur_y})) {
                        q.push({cur_x, cur_y});
                        graph.erase({cur_x, cur_y});
                    }
                }
            }
            if (flag) break;
        }
        ans[t] = step-1;
    }
    for (int num : ans) cout << num << endl;

    return 0;
} */









/* 4. 输入：第一行给出n，第二行输入n个整数，有正有负，绝对值[1, 65536]，输出一行，使得这些数字按照满足 a[i]*a[i+1]<=a[i+1]*a[i+2] 的方式排列输出，其中1<=i<=n-1, N<=100000
12
-9 -5 5 6 4 3 0 0 -2 -1 -7 -4
-9 6 -7 5 -5 4 -4 3 0 0 -1 -2

12
-9 -5 -7 -6 0 2 5 6 1 4 10 4
-9 10 -7 6 -6 5 -5 4 0 1 2 4
 */
// 非负-正-非负-正交替排列，其中非负数升序，正数降序；若之后剩余正数，这些要升序排列；若最后剩余负数，这些要降序，根据交替结束后数组长度insert在合适位置上

/* #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        vec[i] = tmp;
    }
    sort(vec.begin(), vec.end());
    int idx = 0;
    for (; idx < n; ++idx) 
        if (vec[idx] > 0) break;
    if (idx == 0) {
        for (int num : vec) cout << num << " ";
        return 0;
    }
    else if (idx == n) {
        auto rit = vec.rbegin();
        while (rit != vec.rend()) {
            cout << *rit << " ";
            rit++;
        }
        return 0;
    }
    else {
        vector<int> npositive(vec.begin(), vec.begin()+idx);
        vector<int> positive(vec.begin()+idx, vec.end());
        
        vector<int> ans;
        auto it = npositive.begin();
        auto rit = positive.rbegin();
        while (it != npositive.end() && rit != positive.rend()) {
            ans.push_back(*it);
            it++;
            ans.push_back(*rit);
            rit++;
        }
        int len = ans.size();
        while (rit != positive.rend()) {
            ans.insert(ans.begin()+len-1, *rit);
            rit++;
        }
        while (it != npositive.end()) {
            ans.insert(ans.begin()+len, *it);
            it++;
        }
        
        for (int num : ans) cout << num << " ";
        return 0;
    }

    return 0;
} */