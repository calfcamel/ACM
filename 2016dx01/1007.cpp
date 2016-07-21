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
#define ONES(x) __builtin_popcount(x)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = 100000 + 5;
long long dp[2][1 << 10];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!= EOF)
    {
        int cur = 0;
        clr(dp[cur],0);
        dp[cur][0] = 1;
        FOR(i,n)
        {
            clr(dp[cur ^ 1], 0);
            FOR(now, 1 << m) if(dp[cur][now])
            {
                FOR(add, 1 << m) if(add)
                {
                    int mask = add;
                    int tmpnow = now;
                    FOR(t,m << 1)
                    {
                        FOR(k,m)
                        {
                            if((now & (1 << k)) && k && (mask & (1 << k)) && (mask & (1 << (k - 1))))
                                now |= (1 << (k - 1));
                            if((now & (1 << k)) && k + 1 < m && (mask & (1 << k)) && (mask & (1 << (k + 1))))
                                now |= (1 << (k + 1));
                            if((mask & (1 << k)) && k && (now & (1 << k)) && (now & (1 << (k - 1))))
                                mask |= (1 << (k - 1));
                            if((mask & (1 << k)) && k + 1 < m && (now & (1 << k)) && (now & (1 << (k + 1))))
                                mask |= (1 << (k + 1));
                        }
                    }
                    now = tmpnow;
                    //printf("  add %d %d %d %lld\n",now,add,mask, dp[cur][now] * (1 << ONES(add)));
                    dp[cur ^ 1][mask] += dp[cur][now] * (1 << ONES(add));
                    dp[cur ^ 1][mask] %= MOD;
                }
            }
            cur ^= 1;
            //printf("level %d\n",i);
            FOR(now, 1 << m) if(dp[cur][now])
            {
                ;//printf("\t%d : %lld\n",now, dp[cur][now]);
            }
        }
        long long ans = dp[cur][(1 << m) - 1];
        printf("%lld\n", ans);
    }
    return 0;
}
