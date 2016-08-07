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
int a[1003];
int b[1003];
int dp[1003][1003];
void upd(int &x ,int y)
{
    x += y;
    if(x > MOD) x -= MOD;
    if(x < 0) x += MOD;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        FORR(i,n) scanf("%d",&a[i]);
        FORR(j,m) scanf("%d",&b[j]);
        int ans = 0;
        REP(i,0,n) REP(j,0,m) dp[i][j] = 0;
        FORR(i,n) FORR(j,m)
        {
            if(a[i] == b[j])
            {
                upd(ans,dp[i - 1][j - 1] + 1);
                upd(dp[i][j],dp[i - 1][j - 1] + 1);
                //dp[i][j] += dp[i - 1][j - 1];
                //cout << "ADD " << i << " " << j << " : " << ans << endl;
            }
            upd(dp[i][j], dp[i - 1][j]);
            upd(dp[i][j], dp[i][j -1]);
            upd(dp[i][j], -dp[i - 1][j - 1]);
            // dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            //cout <<"\tdp "<< i << " " << j << ": " << dp[i][j] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
