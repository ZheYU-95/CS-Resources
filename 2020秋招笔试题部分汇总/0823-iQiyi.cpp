/* 正整数n的阶乘(n!)中的末尾有多少个0? 例如：n = 5, n! = 120.末尾有1个0 实现：int CountZero(int n); */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n >= 5){
        cnt += n / 5;
        n /= 5;
    }
    cout << cnt;
    return 0;
}




/* 2. 给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。
机器人从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。
如果路径在任何位置上出现相交的情况，也就是走到之前已经走过的位置，请返回 True ；否则，返回 False 。
 */

/* #include <iostream>
#include <string>
#include <utility>
#include <set>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int n  = str.size();
        if (n == 0) {
            cout << "False" << endl;
            continue;
        }
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        pair<int, int> pos = {0, 0};
        for (int i = 0; i < n; ++i) {
            pair<int, int> dir;
            if (str[i] == 'E') dir = {1, 0};
            else if (str[i] == 'S') dir = {0, -1};
            else if (str[i] == 'W') dir = {-1, 0};
            else  dir = {0, 1};
            int x = pos.first + dir.first;
            int y = pos.second + dir.second;
            if (visited.count({x, y}) != 0) {
                cout << "True" << endl;
                break;
            }
            visited.insert({x, y});
            pos.first = x;
            pos.second = y;
            cout << x << y << " ";
        }
        // cout << visited.size();
        if (visited.size()-1 == n) cout << "False" << endl;  
    }
    
    return 0;
} */





/* 3. 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：1. 左括号必须用相同类型的右括号闭合。2. 左括号必须以正确的顺序闭合。注意空字符串可被认为是有效字符串。 */



/* #include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;
int main() {
    string str;
    unordered_map<char, char> mp({{'(',')'}, {'[',']'}, {'{','}'}});
    cin >> str;
    int n = str.size();
        stack<char> stk;
        int i = 0;
        for (; i < n; ++i) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') stk.push(str[i]);
            else {
                if (stk.empty()) break;
                else {
                    if (str[i] == mp[stk.top()]) stk.pop();
                    else break;
                }
            }
        }
        if (i == n && stk.empty()) cout << "True" << endl;
        else cout << "False" << endl;
    return 0;
} */