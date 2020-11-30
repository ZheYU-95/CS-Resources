/* 1. 输入N个字符串，两个字符串有限次字符变换顺序可以相等为一组，问一共N个字符串可以分为几组 */

/* #include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> occur(n, vector<int>(26, 0));
    unordered_set<string> my_set;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (char ch : str) {
            int idx = ch - 'a';
            occur[i][idx]++;
        }
        string s;
        for (int j = 0; j < 26; ++j) {
            s += to_string(occur[i][j]);
        }
        my_set.insert(s);
    }
    cout << my_set.size() << endl;

    return 0;
} */



/* 2. 输入两个字符串str exp，str只含有小写字母，exp除了小写之外还有.（表示任何一个字符）*（前一个字符有0/多个）
*不能在开头，不能连续，问str与exp是否匹配 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string str, exp;
    cin >> str;
    cin >> exp;
    if (exp[0] == '*' || (exp[0] != '.' && exp[0] != str[0])) {
        cout << "NO" << endl;
        return 0;
    }
    int n = str.size(), m = exp.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (exp[j] == '*' && exp[j] == exp[j-1]) {
                cout << "NO" << endl;
                return 0;
            }
            if (dp[i-1][j-1] && str[i] == str[i-1] && (exp[j]=='*' || exp[j] == exp[j-1])) dp[i][j] = 1;
        }
    }
    if (dp[n-1][m-1]) cout << "YES" << endl;
    else cout << "YES" << endl;
    return 0;
}