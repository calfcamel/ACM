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
int n;
double dp[18][1 << 18];
double a[18][18];
int main()
{
    scanf("%d",&n);
    FOR(i,n) FOR(j,n) scanf("%lf",&a[i][j]);
    clr(dp,0);
    dp[0][(1 << n) - 1] = 1.0;
    for(int mask = (1 << n) - 2; mask > 0; mask--)
    {
        for(int i = 0; i < n; i++) if(mask & (1 << i))
            for(int j = 0; j < n; j++) if(!(mask & (1 << j)))
            {
                cmax(dp[i][mask], a[i][j] * dp[i][mask | (1 << j)] + a[j][i] * dp[j][mask | (1 << j)]);
            }
    }
    double ans = 0;
    FOR(i,n) cmax(ans, dp[i][1 << i]);
    printf("%.10f\n",ans);
    return 0;
}
