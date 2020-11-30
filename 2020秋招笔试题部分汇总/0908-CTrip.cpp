/* 1.考虑实现一个敏感词过滤的功能，给定指定的敏感单词、句子、替换词，把句子中的敏感单词词全部替换成替换词。
注意替换过程中敏感词需要忽略字母顺序，例如you这个敏感词，句子里如果出现oyu、uyo等，也同样需要进行替换，以免有人利用不影响人类理解的错误字母顺序钻空子。
输入描述：输入为三行内容：
第一行是敏感单词
第二行是待检测的句子
第三行是替换的目标词
输出描述：输出替换好敏感词的句子 
apple
you love app, i love appe, he loves ppleaa, they love lepap, we love apple!!!!
Orange  
*/
/* #include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 字符串读入一句话，把他分割成各个单词
    string sensitive, target;
    vector<string> sentence;
    string tmp;
    cin >> sensitive;
    cin.ignore();
    getline(cin, tmp);
    cin >> target;
    int pos = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] == ' ') {
            sentence.push_back(tmp.substr(pos, i-pos));
            sentence.push_back(" ");
            pos = i+1;
        }
        else if (!isalpha(tmp[i])) {
            sentence.push_back(tmp.substr(pos, i-pos));
            string s(1, tmp[i]);
            sentence.push_back(s);
            pos = i+1;
        }
    }
    unordered_map<char, int> cnt;
    for (char ch : sensitive) cnt[ch]++;

    for (string& s : sentence) {
        if (s.size() != sensitive.size()) continue;
        else {
            if (s == sensitive) {
                s = target;
                continue;
            }
            unordered_map<char, int> cnt_cpy(cnt);
            bool flag = true;
            for (char c : s) {
                if (!cnt_cpy.count(c)) {
                    break;
                    flag = false;
                }
                else cnt_cpy[c]--;
            }
            if (!flag) continue;
            for (auto x : cnt_cpy) {
                if (x.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) s = target;
        }
    }
    for (string s : sentence) cout << s;
    
    return 0;
} */




/* 业务流
背景: 订单系统的业务逻辑处理，通过采用工作流的方式进行处理，基于面向配置编程以利于后续扩展与维护.
要求: 当前需要根据工作流的配置解析和找出所有工作流路径, 可能存在循环依赖路径. 
说明: 空格隔开的字符串每一个字母都代表一个节点. 比如a bc e, 表示a的下一个节点为b或者c， 输出为:abe, ace.
举例: 有3个分支，输入,a bc df gh 输出如下， 结果输出根据单个字符的下标index排序: abdg abdh abfg abfh acdg acdh acfg acfh

输入描述 输入工作流程配置(可能存在循环依赖路径)
输出描述 找出所有的路径, 正常路径与循环依赖路径,  并且必须标识出循环依赖路径(后缀为--circular dependency),  当前实例题仅为2个分支场景. 3个或3个以上分支请见上面举例
样例输入： a bc d eag f
样例输出
abdef
abdaf--circular dependency
abdgf
acdef
acdaf--circular dependency
acdgf
提示：约束: 1个字母代表下一个节点.abae: 由于a最终会流转回a, 证明这个是错误的配置即循环依赖路径， 输出带后缀说明: abae--circular dependency
根据单个字符的下标index排序， 结果的排序:  Comparator.naturalOrder() 
*/
// 回溯算法

/* 
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void backTrack(int idx, vector<string>& flow, string& path, vector<string>& res) {
    int n = flow.size();
    if (idx == n) {
        unordered_set<char> dict;
        for (char c : path) dict.insert(c);
        if (dict.size() < n) res.push_back(path+"--circular dependency");
        else res.push_back(path);
        return;
    }
    for (char ch : flow[idx]) {
        path.push_back(ch);
        backTrack(idx+1, flow, path, res);
        path.pop_back();
    }
    return;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> flow;
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            flow.push_back(s.substr(pos, i-pos));
            pos = i+1;
        }
        else if (s[i+1] == '\0') flow.push_back(s.substr(pos));
    }
    vector<string> res;
    string path;
    backTrack(0, flow, path, res);
    for (string str : res) cout << str << endl;

    return 0;
}
*/




















/* 3.你现在进入到一个M x N个格子的二维空间探险，有一辆破旧的电瓶车辅助你在不同格子之间移动。探险的目的是找到从起点到终点的最短路径。
电瓶车由电池驱动，电池初始电量为E0，同时会有X个充电机会，电池充满电之后电量为L。车在不同格子之间移动的规则如下：
车只可以前、后、左、右4个方向移动，而且不能跨越二维空间的边界。
每个格子会标记它消耗的电量w (>=0)电量，车进入的瞬间电池会消耗相应电量。重复进入同一格子任然会消耗同样电量。
格子消耗的电量可能大于L。因为探险开始时车已经进入了起点格子，所以初始电量E0已经预先扣除了初始格子的相应电量消耗，不需要重复调整。
方向盘损坏，在行进过程中无法转向，只能等车停止后调整方向。
刹车失灵无法制动，两种条件下电瓶车会停止：a.  遇到边界; b. 电量不足以进入下一个格子
为简单起见，限定电池充电的条件：只有车因为电量不足在某个方向无法前进的时候才可以使用充电机会
一系列整数：M N E0 X L 之后是代表二维空间格子耗电量的系列整数：array[0][0]，array[0][1], …, array[0][N-1], array[1][0], … array[M-1][N-1]。
为简单起见，起点和终点坐标分别默认为[0，0]和[M-1][N-1]
在最短路径上经过格子的个数；如果无解则输出NA
样例输入：6 8 15 0 45  10 1 30 10 1 10 1 1 20 1 1 30 1 1 10 1 10 50 1 1 1 1 1 100 20 10 20 20 1 1 1 100 20 10 10 10 1 1 100 1 30 30 30 20 100 1 1 0
样例输出：16
*/



#include <iostream>
#include <vector>
#include <utility>
using namespace std;
static const int dirs[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};  // prev_dir: 0123上下左右

void dfs(pair<int, int> pos, int pre_dir, vector<vector<int>>& graph, int oppo, int init, int elect, vector<vector<int>>& visited, int cnt, vector<int>& res) {
    int x = pos.first, y = pos.second;
    visited[x][y] = 1;
    int m = graph.size(), n = graph[0].size();

    if (x == graph.size()-1 && y == graph[0].size()-1) {
        res.push_back(cnt);
        return;
    }

    // 车辆行进途中不能转弯，只有遇到边界/没电停下来才可以转向
    int nxt_x = x + dirs[pre_dir][0];
    int nxt_y = y + dirs[pre_dir][1];
    if (nxt_x<0 || nxt_y<0 || nxt_x>=m || nxt_y>=n || visited[nxt_x][nxt_y] || elect<graph[nxt_x][nxt_y]) {
        for (int i = 0; i < 4; ++i) {
            nxt_x = x + dirs[i][0];
            nxt_y = y + dirs[i][1];
            if (nxt_x<0 || nxt_y<0 || nxt_x>=m || nxt_y>=n || visited[nxt_x][nxt_y]) continue;
            if (elect < graph[nxt_x][nxt_y]) {
                if (!oppo || init < graph[nxt_x][nxt_y]) continue;
                else dfs({nxt_x,nxt_y}, i, graph, oppo-1, init, init-graph[nxt_x][nxt_y], visited, cnt+1, res);
            }
        }
    }
    else dfs({nxt_x,nxt_y}, pre_dir, graph, oppo, init, elect-graph[nxt_x][nxt_y], visited, cnt+1, res);  
    
    visited[x][y] = 0;
    
    return;
}

int main() {
    int m, n, e, x, l;
    cin >> m >> n >> e >> x >> l;
    vector<vector<int>> graph(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<int> res;
    dfs({0,0}, 3, graph, x, e, e, visited, 1, res);
    visited.assign(m, vector<int>(n, 0));
    dfs({0,0}, 1, graph, x, e, e, visited, 1, res);

    if (res.empty()) {
        cout << "NA" << endl;
        return 0;
    }
    int count = 1000;

    // for (int num : res) cout << num << " ";
    for (int num : res) count = min(num, count);
    cout << count << endl;
    return 0;
} 