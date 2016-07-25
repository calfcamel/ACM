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
int dp[5002][2];
int ans[100005];
char s[5005];
char p[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d%s%s",&n,&m,p,s);
        FOR(i,n)
        {
            ans[i] = 0;
            if(i + m > n) continue;
            dp[0][0] = 0;
            dp[0][1] = 0;
            dp[1][1] = 0;
            dp[1][0] = 0;
            dp[m - 1][0] = 0;
            dp[m][0] = 0;
            dp[m - 1][1] = 0;
            dp[m][1] = 0;
            if(p[i] == s[0]) dp[1][0] = 1;
            if(i + 1 < n && p[i + 1] == s[0]) dp[1][1] = 1;
            //if(i && p[i - 1] == s[0]) dp[1][0] = 1;
            for(int j = 1; j < m; j++)
            {
                dp[j + 1][0] = 0;
                dp[j + 1][1] = 0;
                if(dp[j][1] && p[i + j - 1] == s[j]) dp[j + 1][0] = 1;
                if(dp[j][0])
                {
                    if(p[i + j] == s[j]) dp[j + 1][0] = 1;
                    if(i + j + 1 < n && p[i + j + 1] == s[j]) dp[j + 1][1] = 1;
                }
                if(dp[j + 1][0] + dp[j + 1][1] == 0) break;
            }
            if(dp[m][0]) ans[i] = 1;
        }
        FOR(i,n) printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
