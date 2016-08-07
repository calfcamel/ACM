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
int dp[2][1001][3][3];
const int mod = 1000000007;
inline void upd(int &x, int y)
{
    x += y;
    if(x > mod) x -= mod;
}
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        int n,s;
        scanf("%d%d",&n,&s);
        int cur = 0;
        clr(dp[cur],0);
        dp[cur][0][0][0] = 1;
        int x;
        int nk;
        int nl;
        FOR(i,n)
        {
            clr(dp[cur ^ 1], 0);
            scanf("%d",&x);
            REP(j,0,s) FOR(k,3) FOR(l,3)
            {
                if(k < 2) if(j + x <= s) upd(dp[cur ^ 1][j + x][k + 1][l], dp[cur][j][k][l]);
                if(j + x <= s) upd(dp[cur ^ 1][j + x][k][l], dp[cur][j][k][l]);
                if(l < 2) upd(dp[cur ^ 1][j][k][l + 1], dp[cur][j][k][l]);
                upd(dp[cur ^ 1][j][k][l], dp[cur][j][k][l]);
            }
            cur ^= 1;
        }
        int ans = 0;
        FORR(j,s) upd(ans, dp[cur][j][2][2]);
        upd(ans,ans);
        upd(ans,ans);
        printf("%d\n",ans);
    }
    return 0;
}
