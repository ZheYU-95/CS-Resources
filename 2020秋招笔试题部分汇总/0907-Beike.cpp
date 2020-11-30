/* 1.T回合，石头剪刀布SJB，每个回合输入：妹左手/妹右手/牛左手/牛右手，妹必须要赢，平局算输，输出赢的概率更大的那只手，两只手一面一样输出same */
/* #include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<char, char> win = {{'S','J'}, {'J','B'}, {'B','S'}};
    int t;
    cin >> t;
    vector<string> res(t);
    for (int i = 0; i < t; ++i) {
        char sister[2], boy[2];
        cin >> sister[0] >> sister[1] >> boy[0] >> boy[1];
        int prob[2] = {0, 0};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (boy[i] == win[sister[j]]) prob[j]++;
            }
        }
        if (prob[0] > prob[1]) res[i] = "left";
        else if (prob[0] < prob[1]) res[i] = "right";
        else res[i] = "same";
    }
    for(string str : res) cout << str << endl;

    return 0;
} */





/* 2. 构造字符串：方法一添加任意一个字符；方法二复制粘贴之前所有添加的字符，只能使用一次，多少步可以完成构造。字符串长度1<=n<=100000 */
/* #include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string str;
    getline(cin, str);
    int l = 0;
    for (int len = n/2; len > 0; --len) {
        for (int pos = 0; pos+2*len <= n; pos++) {
            string tmp = str.substr(pos, len);
            auto found = str.find(tmp, pos+len-1);
            if (found == string::npos) continue;
            l = len;
            break;
        }
        if (l) break;
    }
    cout << n-(l-1) << endl;
    
    return 0;
} */






/* 3.T组数据，每组：n个栅栏，m个颜料，k个每种颜料后不能紧跟的颜料种类数，接下来m行，每行k个整数表示不能进跟的k个颜色的编号（1...m)
输出：每组数据一个数字表示涂色方案数，结果对1e9+7取模 */
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
static const int mod=1e9+7;
static const int maxn=1010;
int dp[maxn][11], mp[11][11];
int main() {
    int T,N,M,K,x;
    scanf("%d",&T);
    while(T--){
        memset(mp,0,sizeof(mp));
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=M;i++){
            for(int j=1;j<=K;j++){
                scanf("%d",&x);
                mp[x][i]=1;  // x颜色后不能接i颜色
            }
        }
        dp[0][0]=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                for(int k=0;k<=M;k++){
                    if(!mp[j][k]) {
                        dp[i][j]+=dp[i-1][k];
                        if(dp[i][j]>=mod) dp[i][j]-=mod; // 第i块板子上涂j颜色的方案数
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=M;i++) {
            ans+=dp[N][i];
            if(ans>=mod) ans-=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}












/* 4.输入n表示线段[-n,n]，其中[-n,-1],[1,n]区域内有怪，打怪必须按照顺序从-1/1开始由近到远，每个整数位置都有一个怪共2n个，每个怪打完掉血lost[i]，回血gain[i]
全程血量必须大于零，问初始血量最少为多少？假设血量没有上限。第二行lost表示每个位置掉血量，第三行gain表示每个位置回血量
5
2 3 2 6 5 1 7 5 3 4
10 3 3 9 1 11 4 6 8 5 */

/* #include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lost1(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        lost1[i] = tmp;
    }
    vector<int> lost2(n);
    for (int i = n-1; i >= 0; --i) {
        int tmp;
        cin >> tmp;
        lost2[i] = tmp;
    }
    vector<int> gain1(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        gain1[i] = tmp;
    }
    vector<int> gain2(n);
    for (int i = n-1; i >= 0; --i) {
        int tmp;
        cin >> tmp;
        gain2[i] = tmp;
    }

    vector<int> dp1(n, INT_MAX);
    dp1[0] = lost1[0]+1;
    vector<int> dp2(n, INT_MAX);
    dp2[0] = lost2[0]+1;
    for (int i = 1; i < n; ++i) {
        dp1[i] = (dp1[i-1]<gain1[i]+1 ? 1 : dp1[i-1]-gain1[i]) + lost1[i];
        dp2[i] = (dp2[i-1]<gain2[i]+1 ? 1 : dp2[i-1]-gain2[i]) + lost2[i];
    }
    if (dp1[n-1] > dp2[n-1]) cout << dp2[n-1] << endl;
    else cout << dp1[n-1] << endl;

    return 0;
}  */





/* 5.家谱 第一行输入整数n，表示家谱中人数，编号1~n，接下来n-1行每行两个整数w,r表示二者是父子关系（树中有一条边相连，但不知道谁是谁父亲）
接下来一行有n个整数，表示每个人的孩子的个数，接下来一行一个整数q表示询问次数，接下来q行，每行两个正整数u,v
输出：对于每组询问，若u是v的祖先输出ZZZZ；若v是u的祖先输出SSSS；若互相都不是另一个的祖先，输出他们最近的公共祖先的编号 */
// https://blog.csdn.net/blowfire123/article/details/108457044

#include <iostream>
#include <vector>
using namespace std;

