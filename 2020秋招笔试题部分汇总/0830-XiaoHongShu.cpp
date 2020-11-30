/* 1. 消息分段：为了满足消息发送的要求，我们需要将一大段文本分成多个消息发送，每个消息最大长度不超过1024个英文字符，
文本内容为英文字符和英文标点符号（包括”,”/“.”/“;”/“!”以及换行），为了尽可能保证可读性，我们希望每一个消息尽可能是分在段落结束。
如果不行，可以分在句子结束。可以保证输入的文本内容每个句子长度不超过1024（包括符号）。请给出拆分算法。 String[] splitMsg(String textContent)
输入：一段文本（英文字符加英文符号）   输出：String的数组，每个数组长度不超过1024字节。内容为分段或者分句 */
/* #include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

vector < string > splitMsg() {


}

int main() {
    vector < string > res;

    
    res = splitMsg();
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}
 */












/* 2. 小明情人节想给女朋友送一束花，但是他想给女朋友开个玩笑，于是找来很多高度和直径不等的圆柱形包装盒，
一层一层地包装花（即先用一个小盒子包装花，再用一个稍大的盒子包装小盒子，以此类推，要求外面的盒子高度和直径都大于里面一层的盒子），
给出所有的盒子数据，求最多能包装多少个盒子。假设花可以装进最小的盒子. 
输入：所有数值均为正整数. 输入为一个二维自然数组,第一行为行数，第二行为列数，后续每行代表一个盒子,  第一列为盒子高, 第二列为盒子直径. 
输出：最多包装盒子个数 */

/* #include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

int maxBoxes(vector<vector<int>>& boxes) {
    int cnt = 0;
    int m = boxes.size();
    if (!m) return cnt;
    for (int i = 0; i < m; ++i) {
        if (boxes[i].size() ！= 2) {
            return cnt;
        }
    }

    vector<int> dp(m, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1]) dp[i] = max(dp[i], dp[j] + 1);
        }
        cnt = max(cnt, dp[i]);
    }
    return cnt;
}

int main() {
    int res;

    int _boxes_rows = 0;
    int _boxes_cols = 0;
    cin >> _boxes_rows >> _boxes_cols;
    vector< vector < int > > _boxes(_boxes_rows);
    for(int _boxes_i=0; _boxes_i<_boxes_rows; _boxes_i++) {
        for(int _boxes_j=0; _boxes_j<_boxes_cols; _boxes_j++) {
            int _boxes_tmp;
            cin >> _boxes_tmp;
            _boxes[_boxes_i].push_back(_boxes_tmp);
        }
    }
    sort(_boxes.begin(), _boxes.end());
    
    res = maxBoxes(_boxes);
    cout << res << endl;
    
    return 0;

} */












/* 3. 矩阵谜题：在神秘岛屿的深处，你发现了海贼王罗杰留下的谜题，呈现在你面前的是一个n*m的宝箱矩阵，
每个宝箱中有一定数量的金币，你需要从这个矩阵中选出r行c列的子矩阵，使得这个子矩阵中每两个相邻的宝箱的金币差之和最小（相邻包括上下左右四个方向）。 
输入：n m r c (n行m列的矩阵中选择r行c列, 0<r<=n, 0<c<=m)，接下来的n行，每行包含m个用空格隔开的整数，表示宝箱内的金币数。
4 4 2 2
5 4 2 6 
4 10 1 8
1 9 3 10
6 4 8 3
输出：1个整数(子矩阵中相邻宝箱的金币差之和的最小值) 
4 */

// https://www.cnblogs.com/GDOI2018/p/9732757.html

#include <iostream>
#include <vector>
using namespace std;

const int maxn=20;
const int INF=2147483647;
int a[maxn][maxn];
int n,m,r,c,ans;
int vish[maxn],hc[maxn][maxn],lc[maxn],f[maxn][maxn];
void Memset()                                                     //预处理
{
    for(int i=1; i<=m; i++)
       lc[i]=0;
    for(int i=1; i<=m; i++)
       for(int j=1; j<=m; j++)
          hc[i][j]=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<r; j++)
            lc[i]+=abs(a[vish[j]][i]-a[vish[j+1]][i]);
    for(int i=2; i<=m; i++)
        for(int j=1; j<i; j++)
            for(int k=1; k<=r; k++)
                hc[i][j]+=abs(a[vish[k]][i]-a[vish[k]][j]);
}
void makeans()
{
    f[1][1]=lc[1];
    for(int i=2; i<=m; i++)
    {
        for(int j=1; j<=(i<c?i:c); j++)
        {
            f[i][j]=INF;
            if(j==1) f[i][j]=lc[i];                              //边界
            else if(i==j) f[i][j]=f[i-1][j-1]+hc[i][j-1]+lc[i];  //边界*2
            else
            {
                for(int k=i-1; k>=j-1; k--)
                   f[i][j]=min(f[i][j],f[k][j-1]+hc[i][k]+lc[i]); //状态转移方程
            }
            if(j==c) ans=min(ans,f[i][c]);                        //记录最小值
        }
    }
    return ;
}
void dfs(int k,int j)                                             //回溯法求组合数
{
    if(k==r+1) {Memset();makeans();return ;}
    for(int i=j+1; i<=n; i++)
    {
        vish[k]=i;
        dfs(k+1,i);
    }
}
int main()
{
    ans=INF;
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=1; i<=n; i++)
       for(int j=1; j<=m; j++)
          scanf("%d",&a[i][j]);
    dfs(1,0);
    printf("%d",ans);
    return 0;
}