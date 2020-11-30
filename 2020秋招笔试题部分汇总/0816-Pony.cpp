/* 1. 车辆沿着y轴运动，初始车辆位置由一条对角线上两个点的坐标确定
输入：第一行T组数据，每一组数据：第一行ADV_X1, ADV_Y1, ADV_X2, ADV_Y2表示车辆的一条对角线的两个点的坐标；第二行n片水迹；
接下来n行的每一行：mi个顶点 X1, Y1, ......Xmi, Ymi，mi个顶点按逆时针顺序排列顶点坐标
n片水迹之间不相交不包含

1
-35 2 3 -1
3
4 -83 7978 14 7981 -16 8057 -82 8057
4 -86 9318 -85 9262 13 9250 -2 9350
4 -101 4934 -65 4873 -5 4888 -11 4935

输出：k 车辆压到水迹的总次数，接下来k行，每行输出第i次压到水迹累计的行驶路程，输出误差1e-8 */

// 思路：水迹的相邻两个顶点依次连起来，判断与车辆两个顶点的射线x=ADV_X1, x=ADV_X2能否相交，若相交计算交点的纵坐标，取第一次与这片水迹相交的最小的y值

/* #include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        vector<vector<vector<double>>> waters(n);
        for (int j = 0; j < n; ++j) {
            int m;
            cin >> m;
            waters[j] = vector<vector<double>>(m, vector<double>(2, (double)0.0));
            for (int k = 0; k < m; ++k) {
                int xk, yk;
                cin >> xk >> yk;
                waters[j][k][0] = xk;
                waters[j][k][1] = yk;
            }
        }
        vector<double> res;
        for (int j = 0; j < n; ++j) {
            double tmp = 10000000;
            double pre_xk, pre_yk, post_xk, post_yk;
            double ans1, ans2;
            bool flag1 = false;
            for (int k = 1; k < waters[j].size(); ++k) {
                pre_xk = waters[j][k-1][0];
                pre_yk = waters[j][k-1][1];
                post_xk = waters[j][k][0];
                post_yk = waters[j][k][1];

                if (x1 >= min(pre_xk,post_xk) && x1 <= max(pre_xk,post_xk)) {
                    ans1 = pre_yk+(post_yk-pre_yk)/(post_xk-pre_xk)*(x1-pre_xk);
                }
                if (x2 >= min(pre_xk,post_xk) && x2 <= max(pre_xk,post_xk)) {
                    ans2 = pre_yk+(post_yk-pre_yk)/(post_xk-pre_xk)*(x2-pre_xk);
                }
                if (ans1 < ans2 && ans1 < tmp) {
                    tmp = ans1;
                    flag1 = true;
                }
                else if (ans2 < ans1 && ans2 < tmp) {
                    tmp = ans2;
                    flag1 = false;
                }
            }
            pre_xk = waters[j][waters[j].size()-1][0];
            pre_yk = waters[j][waters[j].size()-1][1];
            post_xk = waters[j][0][0];
            post_yk = waters[j][0][1];
            if (x1 >= min(pre_xk,post_xk) && x1 <= max(pre_xk,post_xk)) {
                ans1 = pre_yk+(post_yk-pre_yk)/(post_xk-pre_xk)*(x1-pre_xk);
            }
            if (x2 >= min(pre_xk,post_xk) && x2 <= max(pre_xk,post_xk)) {
                ans2 = pre_yk+(post_yk-pre_yk)/(post_xk-pre_xk)*(x2-pre_xk);
            }
            if (ans1 < ans2 && ans1 < tmp) {
                tmp = ans1;
                flag1 = true;
            }
            else if (ans2 < ans1 && ans2 < tmp) {
                tmp = ans2;
                flag1 = false;
            }
            if (tmp == 10000000) continue;
            if (flag1) res.push_back(tmp-y1);
            else res.push_back(tmp-y2);
        }

        cout << res.size() << endl;
        sort(res.begin(), res.end());
        for (double num : res) cout << setprecision(15) << num << endl;
    }
    return 0;
}
 */







/* 2. 输入c行，每行包含 n(目标数字) v1(x=x*3操作所花费的代价) v2(x=x*2操作所花费的代价) v3(x=x-1操作所花费的代价) v4(x=x+1操作所花费的代价)
 * 输出：c行，每行表示从0变到n所花费的最小代价，0<=n<=1e9 */

#include <iostream>
#include <map>
#include <climits>

using namespace std;

// 记忆化递归从n往回推，否则n太大没法申请内存空间
int minCosts(int n, map<int, int>& dp, const int v1, const int v2, const int v3, const int v4) {  
    if (dp.count(n)) return dp[n];
    int tmp1 = min(minCosts(n/2, dp, v1, v2, v3, v4) + v2 + n%2*v4, minCosts(n/3, dp, v1, v2, v3, v4) + v1 + n%3*v4);
    int i = 0;
    while ((n+i)%2 != 0) i++;
    int j = 0;
    while ((n+j)%3 != 0) j++;
    int tmp2 = min(minCosts((n+i)/2, dp, v1, v2, v3, v4) + v2 + i*v3, minCosts((n+j)/3, dp, v1, v2, v3, v4) + v1 + j*v3);
    dp[n] = min(tmp1, tmp2);
    return dp[n];
}

int main() {
    int c;
    cin >> c;
    for (int  i = 0; i < c; ++i) {
        int n;
        cin >> n;
        int v1, v2, v3, v4;
        cin >> v1 >> v2 >> v3 >> v4;

        map<int, int> dp;
        dp.insert({0, 0});
        dp[1] = v4;
        int res = minCosts(n, dp, v1, v2, v3, v4);
        cout << res << endl;

    }
    return 0;
}



/* #include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int c;
    cin >> c;
    for (int  i = 0; i < c; ++i) {
        int n;
        cin >> n;
        int v1, v2, v3, v4;
        cin >> v1 >> v2 >> v3 >> v4;
        
        vector<int> dp(n+1, INT_MAX/2);    //该方法问题在于无法申请过大的n为1e9的数组
        dp[0] = 0;
        if (n > 1) dp[1] = v4;
        for (int i = 1; i < n+1; ++i) {
            if (i-1 >= 0) dp[i] = min(dp[i], dp[i-1]+v4);
            if (i+1 < n+1) dp[i] = min(dp[i], dp[i+1]+v3);
            int next2 = i*2;
            if (next2 < n+1) dp[next2] = min(dp[next2], dp[i] + v2);
            else dp[n] = min(dp[n], (next2-n)*v3 + v2 + dp[i]);   // 如果超过n，只需要直接计算这个数到n所需的花费即可，后面比他大的都要花更多

            int next3 = i*3;
            if (next3 < n+1) dp[next3] = min(dp[next3], dp[i] + v1);
            else dp[n] = min(dp[n], (next3-n)*v3 + v1 + dp[i]);
        }
        for (int num : dp) cout << num << " ";
        // cout << dp[n] << endl;
    }
    return 0;
} */






/* 3. 有AB两种贴纸，为1的部分单独不显色，重叠显色，输入H*W的矩阵，周围一圈全为0，内部部分格子为1；
输出：AB两种贴纸各自为1的部分组成的矩阵，各自必须是连续的，有相邻的1 */