/*
 * @Author: 于哲
 * @Date: 2020-10-26 11:44:13
 * @LastEditTime: 2020-10-26 13:50:56
 * @LastEditors: Please set LastEditors
 * @Description: 2020-10-26 贝壳第二次笔试
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\国内秋招\0.笔试\1026-BeiKe.cpp
 */

/* 1. */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<vector<int>> res(T, vector<int>(3, 0));
    for (int t = 0; t < T; ++t) {
        int x, y, z;
        cin >> x >> y >> z;
        int a = 0, b = 0, c = 0;
        if (x == y) {
            a = x;
            b = z;
            c = 1;
            if (a >= b && a >= c && b >= c) {
                res[t][0] = a;
                res[t][1] = b;
                res[t][2] = c;
            }
            else {
                b = x;
                c = x;
                a = 1;
                if (z == b) {
                    res[t][0] = a;
                    res[t][1] = b;
                    res[t][2] = c;
                }
            }
        }
        else {
            
        }
    }
    return 0;
}



/* 2. */
/* #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> res(T, 0);
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            arr[i] = tmp;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            int num1 = arr[i];
            if (!num1 && !m) {
                res[t] = 1;
                break;
            }
            if (num1 > m) break;
            if (!num1) continue;
            if (m % num1) continue;
            int num2 = m / num1;
            if (binary_search(arr.begin()+i, arr.end(), num2)) {
                res[t] = 1;
                break;
            }
        }
    }
    for (int num : res) {
        if (num) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
    return 0;
} */




/* 4. */
/* #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        int max_a = 0, idx_a = 0;
        vector<int> b(m);
        int max_b = 0, idx_b = 0;

        for (int i = 0; i < m; ++i) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;

            a[i] = tmp1;
            if (a[i] > max_a) {
                max_a = a[i];
                idx_a = i;
            }

            b[i] = tmp2;
            if (b[i] > max_b) {
                max_b = b[i];
                idx_b = i;
            }
        }
        int ans = 0;
        if (max_a <= max_b) ans = a[idx_b] + (n - 1) * max_b;
        else {
            int cnt = 0, flag = 0;
            int a_idx_b = a[idx_b];
            sort(a.begin(), a.end());

            for (int i = m-1; i >= 0; --i) {
                int num = a[i];
                if (num <= max_b || cnt == n) break;
                if (num == a_idx_b) flag = 1;
                ans += num;
                cnt++;
            }
            if (cnt < n) {
                if (flag == 0) ans += a_idx_b + (n - 1 - cnt) * max_b;
                else ans += (n - cnt) * max_b;
            }
        }
        res[t] = ans;
    }
    for (int num : res) {
        cout << num << endl;
    }

    return 0;
} */