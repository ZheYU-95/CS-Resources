/* 1. 输入A,B,a,b，从[1, A]中选择x，从[1, B]中选择y，满足x/y == a/b且x*y最大，输出"x y"，若不存在输出"0 0" */

#include <iostream>

using namespace std;

int main() {
    // const double epsilon = 1e-9;
    int A, B, a, b;
    while (cin >> A >> B >> a >> b) {
        if (A > a && B > b) {
            int k = min(A/a, B/b);
            int i = k, x = 0, y = 0;
            for (; i >= 1; --i) {
                if (i*a <= A && i*b <= B) {
                    x = i*a;
                    y = i*b;
                    break;
                }
            }
            if (i == 0) cout << 0 << " " << 0 << endl;
            else cout << x << " " << y << endl;
        }
        else {
            cout << 0 << " " << 0 << endl;
        }
        
    }
    return 0;
}




/* 2. n个点0-n-1，其中有m条直接相连的双向路，每条路径有一个代价，两点间的代价为各个路径代价的最小值
输入：第一行T组，每一组内：第一行n个点m条路径，接下来m行每行ab两点之间代价为c，之后输入Q次询问次数，接下来Q行每行输入查询值f
输出：Q行，每行表示点对之间的代价>=f的个数（1-2, 2-1这样算作2个） */
/*
2
2 1
0 1 2
3
1
2
3
3 3
0 1 2
0 2 4
1 2 5
5
0
2
3
4
5
*/

// https://blog.csdn.net/qq_39898877/article/details/108208210

#include <iostream>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=10050;
const int maxm=500050;
 
const ll mod=1e9+7;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node{
    int x,y,val;
    bool operator <(const node &b) const{
        return val<b.val;
    }
}a[maxm];
struct qes{
    int id,v,ans;
    bool operator <(const qes &b) const{
        return v<b.v;
    }
}q[maxm];
int fa[maxn],num[maxn],ANS[maxm];
int sum;
int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
void uni(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x==y) return;
    sum+=num[x]*num[y]*2;
    num[x]+=num[y];
    fa[y]=x;
}
int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            num[i]=1;
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val);
            a[i].x++;
            a[i].y++;
        }
        int Q;
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++){
            scanf("%d",&q[i].v);
            q[i].id=i;
            q[i].ans=0;
        }
        sort(q+1,q+1+Q);
        sort(a+1,a+1+m);
        int now=1;
        sum=0;
        for(int i=1;i<=m;i++){
            int limit=a[i].val;
            while(now<=Q&&q[now].v<=limit){
                q[now].ans=sum;
                now++;
            }
            uni(a[i].x,a[i].y);
        }
        while(now<=Q){
            q[now].ans=sum;
            now++;
        }
        for(int i=1;i<=Q;i++){
            ANS[q[i].id]=sum-q[i].ans;
        }
        for(int i=1;i<=Q;i++) printf("%d\n",ANS[i]);
    }
    return 0;
}
