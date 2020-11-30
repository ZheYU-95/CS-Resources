/* 1.跳跃比赛分为两轮，一轮是跳高，一轮是跳远。最终成绩将综合两轮比赛的成绩来确定，并且两轮比赛成绩在最终成绩的计算中各占一半权重。
现在已经知道小小X在跳高和跳远两轮比赛中分别的排名情况，现在请你编写一个程序帮小小X计算一下在最终成绩排名中小小X可以获得的最好名次和最差名次。
输入：第一行输入n，表示参赛人数（n<=26）。
第二行输入n个不重复的大写字母，表示n个人按跳高成绩从最好到最差的排名。
第三行输入n个不重复的大写字母，表示n个人按跳远成绩从最好到最差的排名。
【每个字符对应一个参赛者，不存在排名相同的情况，其中X表示小小X，两个字符之间用空格隔开。 
输出一行，包含两个数分别为小小X在最终排名中的最好名次和最差名次，两个数之间用空格隔开。 */


/* int main() {
    int n;
    cin >> n;
    string high, far;
    unordered_map<char, int> pre, post;
    int idx1 = 0, idx2 = 0;

    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        if (x == 'X') idx1 = i;
        high += x;
    }
    // cout << high;
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        if (x == 'X') idx2 = i;
        far += x;
    }

    for (int i = 0; i < n; ++i) {
        if (i < idx1) {
            pre[high[i]]++;
        }
        else if (i > idx1) post[high[i]]++;
    }

    int best = 1, worst = n;
    for (int i = 0; i < n; ++i) {
        if (i < idx2 && pre.count(far[i])) ++best;
        else if (i > idx2 && post.count(far[i])) --worst;
    }
    cout << best << " " << worst << endl;

    return 0;
} */

/* 2. 这是一个蛇形迂回的斐波那契数列，它是一个n*n的矩阵，在上面的矩阵中n=3。第1行第1列是最大值，然后按照顺时针的次序数字逐渐变小。
单组输入，输入数据占一行，包含一个正整数n，表示斐波那契蛇形矩阵的大小。(n<10)
输出数据占一行，逐行逐列（从第1行开始到第n行，每一行从第1列开始到第n列）输出斐波那契蛇形矩阵中的元素，每两个数字之间用一个空格隔开。 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if(n < 0 || n >= 10){
            return 0;
        }

        //先求出所有的斐波那契数列
        // vector<long long> fibonacci[n*n];    // 大数的数据不能用vector<long long>这种形式，只能long long a[110];
        long long fibonacci[n*n];
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        for(int i = 2; i <= n*n; i++){
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }

        long long res[n][n];
        int l = 0, r = n-1, top = 0, bottom = n-1, idx = n*n-1;
        while (idx >= 0) {
            for (int i = l; i <= r; ++i) res[top][i] = fibonacci[idx--];
            top++;
            for (int i = top; i <= bottom; ++i) res[i][r] = fibonacci[idx--];
            r--;
            for (int i = r; i >= l; --i) res[bottom][i] = fibonacci[idx--];
            bottom--;
            for (int i = bottom; i >= top; --i) res[i][l] = fibonacci[idx--];
            l++;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
