
#include <iostream>
#include <vector>

using namespace std;


// 科大讯飞20200815
/* 1. 一只铁杆顶端，有一只蜗牛。第一天先滑落当前距离的一半，再滑落3米，第二天先滑落当前距离的一半，再滑落3米，
第三天先滑落当前距离的一半，再滑落6米，第四天先滑落当前距离的一半，再滑落9米，第五天先滑落当前距离的一半，再滑落12米。
以此内推，直至滑落到地面。给定滑落到地面的天数，求铁杆的最大高度（不会大于4G）。
输入描述：一个数字，表明滑落至地面的天数，小于36
输出描述：一个数字，表明铁杆最大的高度 */

/* int slidingLen (int i) {
    int prev = 3, cur = 3;
    for (int j = 3; j <= i; ++j) {
        int tmp = prev;
        prev = cur;
        cur += tmp;
    }
    return cur;
}

int main() {
    int n;
    while (cin >> n) {
        vector<long long> dp(n+1, 0);
        for (int i = n; i > 0; --i) {
            dp[i-1] = (long long)2 * (dp[i] + (long long)slidingLen(i));
            cout << slidingLen(i) << endl;
        }
        cout << dp[0] << endl;
    }
    return 0;
} */



// 奇安信20200816
/* 2. 撤销/恢复操作具有广泛的用途，比如word文档中插入一个单词，可以点撤销，然后可以恢复。编程实现如下功能：从标准输入读取到一个字符串，字符串可包含0个或多个单词，单词以空格或者tab分隔；如果遇到“undo”字符串，表示“撤销”操作，前一个字符串被撤销掉；如果遇到“redo”字符串，表示恢复刚才撤销掉的字符串。
例如：输入字符串“hello undo redo word”，对字符串中的undo和redo处理后，最终输出的结果为“hello word”
输入描述：一行字符串：包含0个或多个单词，单词以空格或者tab分隔
输出描述：一行字符串：由0个或多个单词组成，单词以空格分隔 */
#include <stack>

int main() {
    vector<string> strs;
    string str;
    getline(cin, str);
    int l = 0;
    while (l < str.size()) {
        while (str[l] == ' ') l++;
        int r = l;
        while (r < str.size() && str[r] != ' ') r++;
        strs.push_back(str.substr(l, r-l));
        l = r;
    }
    stack<string> stk;
    stack<string> stk_backup;
    for (int i = 0; i < strs.size(); ++i) {
        if (strs[i] == "undo") {
            if (!stk.empty()) {
                stk_backup.push(stk.top());
                stk.pop();
            }
        }
        else if (strs[i] == "redo") {
            if (!stk_backup.empty()) {
                stk.push(stk_backup.top());
                stk_backup.pop();
            }
        }
        // 如果输入的是新字符串，酒吧之前undo备份的栈清空，因为下一次redo前还要有undo才有意义，那时候存入新栈
        // 如 hello undo world redo 输出：world
        else {
            stk.push(strs[i]);
            while (!stk_backup.empty()) stk_backup.pop();
        }
    }
    string res;
    while (!stk.empty()) {
        res = stk.top()+" " + res;
        stk.pop();
    }
    res.pop_back();
    cout << res << endl;
    return 0;
}