/* 1. 求满足下面条件的最长子串：包含a,b,c,d,e中的一个或几个（不必全包含）；以上每种字母出现偶数次，可以不相连；可以出现其他字母；所有均为小写字母
 */

/* #include <iostream>
using namespace std;

int getMaxSubstringLen(string str) {
        int cnt[5] = {0,0,0,0,0};
        bool flag[5] = {1,1,1,1,1};    // 这种形式的赋值！！！{1}只能按顺序给第一个赋值为1
        for (char ch : str) {
            if (ch >= 'a' && ch <= 'e') ++cnt[ch-'a'];
        }
        for (int i = 0; i < 5; ++i) {
            if (cnt[i] == 1) flag[i] = false;
        }
        int res = 0, len = 0;
        int times[5] = {0,0,0,0,0};
        for (int i = 0; i < str.size(); ++i) {
            if (!isalpha(str[i]) || (str[i]>='A' && str[i]<='Z')) len = 0;
            else if (str[i]>'e') res = max(res, ++len);
            else if (!flag[str[i]-'a']) len = 0;
            else {
                bool odd = false;
                times[str[i]-'a']++;
                len++;
                cnt[str[i]-'a']--;
                for (int num : times) {
                    if (num%2) odd = true;
                }
                if (!odd) res = max(res, len);
            }
        }
        return res;
    }

int main() {
    string s;
    while (cin >> s) {
        cout << getMaxSubstringLen(s) << endl;
    }
    return 0;
} */


/* 2. 判断字符串是否相等。字符串相等是指：字符串相等，或者分割成两个长度相同的子串（只能分为长度相等的）后子串相等 */

//简单递归即可


/* 3. 有字母表前n个字母组成的字符串，每个字母至少出现一次，取其中任意两个子串，二者之间无相同字母，各自内部字母可重复，求两子串长度相乘最大值 */

//求两子串长度相乘最大值
