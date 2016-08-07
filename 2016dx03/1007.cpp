#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;

//#pragma comment(linker, "/STACK:102400000,102400000")

#define MP3(x,y,z) make_pair(make_pair(x,y),z)
#define MP make_pair
#define AA first
#define XX first.first
#define YY first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl

const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = 100000 + 5;
struct edge
{
    int v;
    int nxt;
}e[MAXN << 1];
int tot;
int h[MAXN];
void init()
{
    tot = 0;
    clr(h, -1);
}
void adde(int u,int v)
{
    e[tot].v = v;
    e[tot].nxt = h[u];
    h[u] = tot++;
}
int dp[MAXN][3][2];
int g[3][2];
void update(int &dp, int x)
{
    if(dp == 0) dp = x;
    dp = min(dp, x);
}
void dfs(int u, int f)
{
    clr(dp[u], 0);
    int i = h[u];
    while(~i)
    {
        if(e[i].v != f)
        {
            dfs(e[i].v, u);
            clr(g, 0);
            FOR(j,3) if(j) FOR(k,2) FOR(p,3) if(p) FOR(q,2) if(!(k & q))
            {
                if(!(k + q))
                {
                    if(j == 2 && p == 2)
                    {
                        update(g[j + p - 2 - 1])
                    }
                }
            }
            FOR(j,3) FOR(k,2) dp[u][j][k] = g[j][k];
        }
        i = e[i].nxt;
    }
    //leave
    dp[u][1][0]++;
    FOR(j,3) if(j) FOR(k,2) if(j != 1 && k != 0)
    {
        if(dp[u][j][k])
            dp[u][j][k] += j;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        init();
        FOR(i,n - 1)
        {
            scanf("%d%d",&x,&y);
            adde(x,y);
            adde(y,x);
        }
        dfs(1, -1);
    }
    return 0;
}
