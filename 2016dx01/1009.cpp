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

const int HASH = 10007;
const int STATE = 1 << 16;
struct HASHMAP
{
    int head[HASH],size;
    int state[STATE],nxt[STATE];
    LL f[STATE];
    void init()
    {
        size = 0;
        clr(head,-1);
    }
    void push(int st, LL ans)
    {
        ans %= MOD;
        int h = st % HASH;
        int i = head[h];
        while(~i)
        {
            if(state[i] == st)
            {
                f[i] += ans;
                f[i] %= MOD;
                return;
            }
            i = nxt[i];
        }
        state[size] = st;
        f[size] = ans;
        nxt[size] = head[h];
        head[h] = size++;
    }
    LL search(int st)
    {
        int h = st % HASH;
        int i = head[h];
        while(~i)
        {
            if(state[i] == st)
                return f[i];
            i = nxt[i];
        }
        return 0;
    }
}hm[2];
LL f[17][17];
LL gg[17];
LL g[17];
LL ans[17][17];
int main()
{
    FORR(m,16)
    {
        int cur = 0;
        hm[cur].init();
        hm[cur].push(0,1);
        int st;
        LL d;
        FORR(i,m)
        {
            FOR(j,m)
            {
                hm[cur ^ 1].init();
                FOR(it,hm[cur].size)
                {
                    st = hm[cur].state[it];
                    d = hm[cur].f[it];
                    if(st & (1 << j)) hm[cur ^ 1].push(st ^ (1 << j), d);
                    else
                    {
                        if(j + 1 < m && !((1 << (j + 1)) & st)) hm[cur ^ 1].push(st ^ (1 << (j + 1)), d);
                        hm[cur ^ 1].push(st ^ (1 << j), d);
                    }
                }
                cur ^= 1;
            }
            f[i][m] = f[m][i] = hm[cur].search(0);
            //printf("%d %d %lld\n", i, m, f[i][m]);
        }
    }
    FORR(m,16)
    {
        FOR(mask,1 << (m - 1))
        {
            FORR(i,m)
            {
                gg[i] = 1; int p = -1; int now = mask | (1 << (m - 1));
                while(now)
                {
                    int t = now & -now;
                    now ^= t;
                    FOR(tt,20)
                    {
                        if(t == (1 << tt))
                        {
                            t = tt;
                            break;
                        }
                    }
                    gg[i] *= f[i][t - p];
                    gg[i] %= MOD;
                    p = t;
                }
            }
            FORR(i,m)
            {
                g[i] = gg[i];
                FORR(j,i - 1) {g[i] -= g[j] * gg[i - j] % MOD; g[i] += MOD; g[i] %= MOD;}
                if(__builtin_popcount(mask) & 1) ans[i][m] -= g[i];
                else ans[i][m] += g[i];
                ans[i][m] += MOD;
                ans[i][m] %= MOD;
            }
        }
    }
    int n,m;
    while (cin >> n >> m){
        if (m < n) swap(m, n);
        cout << ans[n][m] << endl;
    }
    return 0;
}
