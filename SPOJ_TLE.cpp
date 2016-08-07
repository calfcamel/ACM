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
const int mod = 1000000000;
const int MAXN = 100000 + 5;
inline void upd(int &x ,int add)
{
    x += add;
    if(x > mod) x -= mod;
}
int f[1 << 15];
int g[1 << 15];
int n,m;
int c[55];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        FOR(i,n) scanf("%d",&c[i]);
        FOR(mask, 1 << m)
            f[mask] = mask % c[0] ? 1:0;
        int cmask = (1 << m) - 1;
        REP(i, 1, n - 1)
        {
            FOR(d,m)
                FOR(mask, 1 << m)
                    if(mask >> d & 1)
                        upd(f[mask], f[mask ^ 1 << d]);
            FOR(mask, 1 << m)
            {
                g[mask] = f[mask ^ cmask];
            }
            swap(f,g);
            FOR(mask, 1 << m)
                if(!(mask % c[i]))
                    f[mask] = 0;
        }
        int ans = 0;
        FOR(mask, 1 << m)
            upd(ans, f[mask]);
        printf("%d\n",ans);
    }
    return 0;
}
