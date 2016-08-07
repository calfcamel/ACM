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

const int N = 55;

int dp[N][N][N];
vector<int> v[N];
int n,r;
int f[N];
int son[N];
void dfs1(int now, int pre)
{
    fa[now] = pre;
    son[now] = 0;
    cnt[now] = 1;
    FOR(i, v[now].size())
    {
        if(v[now][i] == pre) continue;
        nc = dfs(v[now][i], now);

    }
}
int main()
{
    while(scanf("%d%d",&n,&r) == 2)
    {
        FORR(i,n) v[i].clear();
        int x,y;
        FOR(i,n - 1)
        {
            scanf("%d%d",&x,&y);
            v[x].PB(y);
            v[y].PB(x);
        }
        clr(dp,-1);
        dfs1(r, -1);

    }
    return 0;
}
