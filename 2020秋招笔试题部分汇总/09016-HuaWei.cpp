/*
 * @Author: your name
 * @Date: 2020-09-16 12:47:24
 * @LastEditTime: 2020-09-16 18:33:14
 * @LastEditors: Please set LastEditors
 * @Description: 华为笔试-通用软件开发
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\09016-HuaWei.cpp
 */


/* 1.按照0,1,2,3,4,3,2,1,5,6,5,7,8,9,8,7,5,1,0线路行进为正常行驶线路。A到F为竖杆。输入为行驶过的区域或撞到的竖杆编号。
1、如果区域字符串出现多次违规记录，则以第一次的为准，违规后的区域忽略不计。
2、同一个区域编号可能连续出线，属于正常，例如0,1,2,2,2,3，等同于0,1,2,3
3、考试成功后任何输入均可以忽略不计
4、已经发生明确的异常导致考试失败后的任何事件视为无效，例如撞杆、越界、未按照规定线路行驶发生后，后续的事件均视为无效。
题目输入：行车经过的区域编号(0~9)顺序及触动的柱子编号(A~F)，例如：0,1,A，表示经过区域0、1，撞到A柱。不用校验输入最大长度；不用校验控制符串；输入严格按照",“分割，不用校验格式。

以下情况均视为考试不合格：
 撞到竖杆。考试结果为：撞杆。输出：Collision
 行驶出行车区域（越界，区域编号为-1）。考试结果为：越界。输出：Out of path
 没有按照规定区域线路行驶。考试结果为：未按照规定线路行驶。输出：：Bad path
如果考试成功输出：Success */

/* #include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    vector<string> str;
    getline(cin, input);
    int i = 0;
    while (i < input.size()) {
        if (input[i] == ',') {
            i++;
            continue;
        }
        string tmp(1, input[i]);
        str.push_back(tmp);
        if (input[i] == '-') {
            str.back().push_back(input[i+1]);
            i += 2;
            continue;
        }
        i++;
    }
    string standard = "0123432156578987510";
    int idx = 0;

    string prev = " ";
    for (string s : str) {
        if (idx == standard.size()-1) {
            cout << "Success" << endl;
            break;
        }
        else if (s == "-1") {
            cout << "Out of path" << endl;
            break;
        }
        else if (isalpha(s[0])) {
            cout << "Collision" << endl;
            break;
        }
        else if (s == prev) continue;
        prev = s;
        if (standard[idx] != s[0]) {
            cout << "Bad path" << endl;
            break;
        }
        idx++;
    }
    cout << standard[18];

    return 0;
} */






/* 2.输入一个无向图，并且所有边的长度都相等。给定起点和终点，尝试判断这个图是否是对称图，并且起点和终点也是对称点。如果是对称图，找到对称轴上所有点id的值之和，否则输出0。
第一行为起点和终点id（0 < id < 100）。
第二行为边的数量N(0 < N < 10000)。
第三行开始是所有的边，由边所连接的两个点的id确定

预期输出为对称轴上的点id之和

1）本题只对点做严格要求对称，不要求边也对称。
2）只有一个点算对称，结果输出该点的值；
3）为了降低复杂度，本题中的对称轴不允许与边相交，这种情况下（例如等边三角形、五边形等）可以认为这个图不是对称的，预期输出结果为0。
4）所有的点都至少有一条边连接，不存在孤立点。
5）如果两个点之间存在边，最多只有一条边，不存在重复边。
6）点id不重复，一个id可以唯一的表征一个点。
7）测试用例保证输入参数合法，不需要进行验证。
1 3
5
1 2
2 4
2 5
3 4
3 5

0
 */

/* #include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int start, terminal;
    cin >> start >> terminal;
    int n;
    cin >> n;
    vector<vector<int>> graph(100);
    for (int i = 0; i < n; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    queue<int> q_s, q_t;
    q_s.push_back(start);
    q_t.push_back(terminal);
    while (!q_s.empty() && !q_t.empty()) {
        if (q_s.size() != q_t.size()) {
            cout << 0 << endl;
            break;
        }
        int node1 = q_s.front(), node1 = q_s.front();
    }
    
    return 0;
} */



/* 3.输入树构造原始数据列表：
Node{parents:string, name:string, link:string}，name表示当前节点名称；parents表示节点父节点名称;link标识当前节点与父节点的链接属性；
输入搜索条件列表:{name:link,…, link|name:link,…, link}，搜索条件已排序，越靠近根节点位置越往前；
根据搜索条件列表，遍历树，返回匹配度最高(不一定是全匹配)的叶子节点名称，如搜索条件匹配到中间节点，则此节点延伸的所有节点的叶子节点都需返回；
返回的搜索结果需按字符串升序排序

第一行为搜索条件
第二行开始，每行是一个Node实例
无需考虑输入异常情况，所有输入都是有效的

满足搜索条件的叶子节点列表，以,间隔
A:10|E:2,3
A,B,30
A,E,10
B,C,50
B,D,30
E,F,3
E,K,2
F,G,30
F,H,0
H,I,PTN
H,J,IP
K,M,30
K,N,50

G,I,J,M,N

 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* struct TreeNode {
    string str;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string s) : str(s), left(nullptr), right(nullptr) {}
}; */

int main() {
    string search;
    getline(cin, search);
    // TreeNode *root = new TreeNode("0");
    vector<vector<string>> graph(30, vector<string>(30));
    string edge;
    while (getline(cin, edge)) {
        if (edge == "") break;
        string node1 = edge.substr(0, 1);
        string node2 = edge.substr(2, 1);
        string relation = edge.substr(4);
        int parent = node1[0]-'A';
        int child = node2[0]-'A';
        graph[parent][child] = relation;
    }
    size_t idx = 0;
    while (idx < search.size()) {
        size_t pos1 = search.find_first_of(':', idx);
        size_t pos2 = search.find_first_of('|', idx);
        int node = search.substr(idx, pos1-idx)[0]-'A';
        string s = search.substr(pos1+1, pos2-pos1);
        vector<string> relas;
        int i = 0, pre = 0;
        for (; i < s.size(); ++i) {
            if (s[i] == ',') {
                string rela = s.substr(pre, i-pre);
                relas.push_back(rela);
                pre = i+1;
            }
        }
        relas.push_back(s.substr(pre, i-pre));

        idx = pos2+1;
    }
    return 0;
}