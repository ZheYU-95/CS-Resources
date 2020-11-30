/*
 * @Author: yuzhe
 * @Date: 2020-09-15 12:56:16
 * @LastEditTime: 2020-09-15 19:34:21
 * @LastEditors: Please set LastEditors
 * @Description: 小米笔试
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\0915-XiaoMi.cpp
 */

/* 1.字符串有效判断 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

int main() {
    unordered_map<char, char> m = {{')','('}, {']','['}, {'}','{'}};
    vector<string> strs;
    string s;
    while (getline(cin, s)) {
        if (s=="") break;
        strs.push_back(s);
    }
    int res[strs.size()];

    for (int i = 0; i < strs.size(); ++i) {
        string str = strs[i];
        if (str.size()%2 == 1) {
            res[i] = 0;
            continue;
        }
        stack<char> stk;
        for (int j = 0; j < str.size(); ++j) {
            if (stk.empty()) stk.push(str[j]);
            else {
                if (str[j]=='(' || str[j]=='[' || str[j]=='{') stk.push(str[j]);
                else {
                    if (stk.top() == m[str[j]]) stk.pop();
                    else break;
                }
            }
        }
        res[i] = stk.empty()? 1 : 0;
    }
    for (int num : res) {
        if (num==1) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}



/* 2. */

/* #include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    unordered_set<char> myset;
    string str;
    string res;
    getline(cin, str);
    for (char c : str) {
        if (myset.count(c)) continue;
        myset.insert(c);
        string tmp(1, c);
        res += tmp;
    }
    cout << res;
    return 0;
} */