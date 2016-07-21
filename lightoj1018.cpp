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

const int MAXN = 16;
int n;
int x[MAXN];
int y[MAXN];
int three_inline(int i, int j, int k)
{
    int x1 = x[i] - x[j];
    int y1 = y[i] - y[j];
    int x2 = x[j] - x[k];
    int y2 = y[j] - y[k];
    return x1 * y2 - x2 * y1 == 0;
}
const int HASH = 1007;
const int STATE = 1 << MAXN;
struct HASHMAP
{
    int tot;
    int state[STATE];
    int head[HASH];
    int dp[STATE];
    int nxt[STATE];
    void init()
    {
        tot = 0;
        clr(head, -1);
    }
    void push(int st, int ans)
    {
        int i,h = st % HASH;
        for(i = head[h]; ~i; i = nxt[i])
            if(state[i] == st)
            {
                if(dp[i] > ans)
                    dp[i] = ans;
                return;
            }
        state[tot] = st;
        dp[tot] = ans;
        nxt[tot] = head[h];
        head[h] = tot++;
    }
    int get(int st)
    {
        int i,h = st % HASH;
        for(int i = head[h]; ~i; i = nxt[i])
        {
            if(state[i] == st)
                return dp[i];
        }
        return -1;
    }
}hm[2];
int vis[MAXN][MAXN];
int st[MAXN * MAXN];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d",&x[i],&y[i]);
        clr(vis,0);
        int now;
        int ltot;
        int la[16];
        int tot = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) if(!vis[i][j])
            {
                ltot = 0;
                now = (1 << i) | (1 << j);
                for(int k = j + 1; k < n; k++) if(!vis[j][k] && !vis[i][k])
                {
                    if(three_inline(i,j,k))
                    {
                        FOR(p,ltot)
                            vis[la[p]][k] = 1;
                        la[ltot++] = k;
                        vis[i][k] = 1;
                        vis[j][k] = 1;
                        now |= (1 << k);
                    }
                }
                st[tot++] = now;
            }
        int cur = 0;
        hm[cur].init();
        hm[cur].push(0,0);
        int ans;
        for(int i = 1; i <= n; i++)
        {
            hm[cur ^ 1].init();
            FOR(j,tot)
                FOR(k,hm[cur].tot)
                    if(__builtin_popcount(st[j] | hm[cur].state[k] ^ hm[cur].state[k]) > 1)
                    hm[cur ^ 1].push(st[j] | hm[cur].state[k], 0);
            cur ^= 1;
            if(hm[cur].get((1 << n) - 1) != -1)
            {
                ans = i;
                break;
            }
        }
        printf("Case %d: %d\n",CAS,ans);
    }
    return 0;
}
