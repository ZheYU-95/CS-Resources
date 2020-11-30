#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Alibaba-2020.07.19
/* 1. 对于给定一个整数x，一定存在若干对整数(a,b)使得x^a^b取到最大值。请求出所有符合要求的(a,b)中满足abs(a-b)最小的方案的个数
输入：第一行一个整数T(1<=T<=150)，代表测试数据总数。接下来有T行，每行数据占一行，仅包含一个整数
输出：对于每组测试数据，输出一行，每行一个整数代表答案 */

// x中0表示a b在该位为01或10，x中1表示二者在该位为00或11。若b更大，则x中最高位的0给a，其余的0给b，可能性即为2^(x中1的位数)；a还可以大于b，总数要乘2

/* int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x) {
            if (x&1) cnt++;
            x >>= 1;
        }
        cout << pow(2, cnt+1) << endl;
    }
    return 0;
} */





// Alibaba-2020.07.22
/* 1. 给一个n<=10，按字典序输出1…n，相邻数字绝对值不为1，的排列。
输入：4
输出：
2 4 1 3
3 1 4 2 */
/* void dfs(int i, vector<int> path, vector<bool> visited, vector<vector<int>>& res) {    // 注意此处不能用引用
    int n = visited.size();
    path.push_back(i+1);
    visited[i] = true;
    if (path.size() == n) {
        res.push_back(path);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (abs(j-i) > 1 && !visited[j]) dfs(j, path, visited, res);
    }
    return;
}

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            vector<int> path;
            dfs(i, path, visited, res);
        }
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
} */






// Alibaba-2020.07.27
/* 1. 小明和小强在玩游戏，现在有一个非递减的数字序列，然后依次进行以下步骤（小强先开始）：
每个人选择一个当前序列中的数字，把这个数字在序列中第一次出现的位置及其左边的数字全部删除，当某人操作完之后序列为空时则此人获胜。
例如：此时的序列是111222，如果小强选择2，那么删除之后得到的序列是22。假设小明和小强都是大佬，请问最后谁能获得游戏胜利？
输入描述：第一行表示的测例数
对于每组数据，第一行一个整数n，n表示序列中数字的个数。接下来一行n个整数，其中a[i]表示第i个整数。
输出描述：对于每组数据。如果小强能获胜，输出“xiaoqiang”。如果小明获胜，输出“xiaoming” */

// 从右到左遍历，有奇数个相同的数字，就是先手赢


/* 2. 有个藏宝架有n层，每层的宝物数量不一，每个宝物都有其价值，现在要求拿出m个宝物，
并且需要遵守规则：每次只能拿选定层的两端的宝物,要拿出的m个宝物的总价值是各种方案里最大的
输入：n m 下面每行代表每层，且第一个数是这层宝物的数量k，后面的则是k个宝物的价值
4 1 2 4 5
5 1 2 4 5 5
样例：
2 3
2 3 2
4 1 4 1 5
输出：5+3+2=10 */

/* int maxOffer(vector<vector<int>>& treasures, vector<vector<int>>& offers) {
    int n = treasures.size();
    int x, y, maxVal = 0;
    for (int i = 0; i < n; ++i) {
        if (offers[i][0] < offers[i][1]) {
            if (maxVal < offers[i][1]) {
                maxVal = offers[i][1];
                x = i; y = 1;
            }
        }
        else {
            if (maxVal < offers[i][0]) {
                maxVal = offers[i][0];
                x = i; y = 0;
            }
        }
    }
    // update offers and treasures
    if (y == 0) {
        treasures[x].erase(treasures[x].begin());
        if (treasures[x].empty()) {
            offers[x][0] = 0;
            offers[x][1] = 0;
        }
        else offers[x][0] = treasures[x].front();
    }
    else {
        treasures[x].erase(treasures[x].begin()+treasures[x].size()-1);
        if (treasures[x].empty()) {
            offers[x][0] = 0;
            offers[x][1] = 0;
        }
        else offers[x][1] = treasures[x].back();
    }
    // cout << maxVal << endl;
    return maxVal;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> treasures;
        vector<vector<int>> offers(n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            treasures.push_back({});
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                treasures.back().push_back(x);
            }
            offers[i][0] = treasures.back().front();
            offers[i][1] = treasures.back().back();
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            res += maxOffer(treasures, offers);
            // cout << res << " ";
        }
        cout << res << endl;
    }
    return 0;
} */





// Alibaba-2020.08.05
/* 1. 输入一个n m 分别代表扑克牌从0 - n，m指从每种牌的4个花色中取出来来m个进行排序 
两种不同的牌型指的是包含对应数字牌的个数不同（与花色无关，只看数字） 一共有多少种排序方法？*/

/* int main() {
    int n, m;
    int mod = 1000000007;
    while (cin >> n >> m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  // dp[i][j]表示取第i个种类的牌，背包容量为j的种类数
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];  // 不取
                if (j >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;  // 第i类取1个
                if (j >= 2) dp[i][j] = (dp[i][j] + dp[i-1][j-2]) % mod;  // 第i类取2个
                if (j >= 3) dp[i][j] = (dp[i][j] + dp[i-1][j-3]) % mod;  // 第i类取3个
                if (j >= 4) dp[i][j] = (dp[i][j] + dp[i-1][j-4]) % mod;  // 第i类取4个
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
} */


/* 2. 有一个初始数组和一个target数组，每次只能移动初始数组的第一个或者最后一个元素到任意位置，要移动多少次才能使两个数组一致 */
// https://blog.csdn.net/liyunlong41/article/details/50410725#reply





// Alibaba-2020.08.14
/* 1. 给一个矩阵，和一个加数，将矩阵元素通过加上有限次加数变成全部元素都相同的步数 */
// 找到最大的数，加不同个数的加数，找到最小的加数使得所有数与目标数差值可以整除加数，计算商的最大值

/* 2. 对由数字构成的字符串中任意长度为2连续的子串，要么第一个元素加一，第二个元素减一。要么第一个减一，第二个加一。求一共能生成多少种不重复的字符串 */
// set<string> 去重，最后计算size





// Alibaba-2020.08.17
/* 1. 求n个节点 高度不超过m的二叉树的个数 结果%1e9+7*/

/* int main() {
    const int mod = 1e9+7;
    int n, h;
    while (cin >> n >> h) {
        // vector<long long> dp(n+1, vector<long long>(h+1, 0));
        long long dp[55][55] = {0};
        for(int i=1;i<=n;i++)
        {  
            dp[0][i-1] = 1;
            for(int j=1;j<=n;j++)
            {
                for(int k=0;k<j;k++) 
                {
                    dp[j][i] =(dp[j][i]%mod+ dp[k][i-1] * dp[j-k-1][i-1]%mod)%mod;
                }
            }       
        }
        cout<<dp[n][h]<<endl;
    }
    return 0;
} */

/* 2. 有n个物品 k个属性 k不超过10 然后求满足ai1+aj1=ai2+aj2=...aik+ajk的对数 */





// Alibaba-2020.08.19
/* 1. 两个数组按照从前端依次选取的方式是否能拼接成相应数组。 */

/* 2. 求k个连续队员中最大体力和的最小个人体力 */





// Alibaba-2020.08.21
/* 1. 在漆黑的夜里，N位旅行者来到了一座狭窄而且没有护栏的桥边。如果不借助手电筒的话，大家是无论如何也不敢过桥去的。
不幸的是，N个人一共只带了一只手电筒，而桥窄得只够让两个人同时过。如果各自单独过桥的话，N人所需要的时间已知；
而如果两人同时过桥，所需要的时间就是走得比较慢的那个人单独行动时所需的时间。问题是，如何设计一个方案，让这N人尽快过桥。*/

//函数功能: 过河问题
//函数参数: T为旅行者的过河时间，n为旅行者个数
//返回值:   最快过河时间
int CrossRiverProblem(int *T, int n) {
	if(n == 1)         //一个旅行者
		return T[0];   
	else if(n == 2)    //两个旅行者
		return T[0] > T[1] ? T[0]: T[1];
	else {              //多个
		sort(T, T + n);//排个序
		int sum = 0;
	
		while(1) {
			if(n == 2) {     //剩两个人
				sum += T[1];
				break;
			}
			else if(n == 3) { //剩三个人
				sum += T[0] + T[1] + T[2];
				break;
			}
			else {
                // 如果N > 3，考虑最慢和次慢两个人的过桥方法。共有两种方案: 
                // 方案1
                // 最快和次快的人先过去（用时T[1]），然后最快的人回来（用时T[0]），
                // 接着最慢和次慢的人过去（用时T[n-1]），最后次快的人回来（用时T[1]）。整理后为T[0] + T[1] + T[1] + T[n-1]
				int t1 = T[0] + T[1] + T[1] + T[n-1];   
                // 方案2
                // 最快和最慢的过去（用时T[n-1]），然后最快的回来（用时T[0]），
                // 接着最快和次慢的人过去（用时T[n-2]），最后次快的人回来（用时T[0]）。整理后为T[0] + T[0] + T[n-1] + T[n-2]
				int t2 = T[0] + T[0] + T[n-1] + T[n-2]; 
				
                sum += (t1 > t2 ? t2 : t1);
				n -= 2;
			}
		}
		return sum;
	}
}