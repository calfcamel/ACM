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

const int MAXN = 410 + 5;
int dp[MAXN * 2][MAXN][MAXN];
int n,m;
int a[MAXN][MAXN];
int hefa(int x,int y)
{
    if(x < 1 || x > n) return 0;
    if(y < 1 || y > m) return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&m,&n);
    FORR(i,n) FORR(j,m)
        scanf("%d",&a[i][j]);
    clr(dp,0);
    dp[2][1][1] = a[1][1];
    int yi;
    int yj;
    FORR(l,n + m) FORR(i,l) REP(j,i,l) if(hefa(i,l - i) && hefa(j,l - j))
    {
        if(i == j)
        {
            cmax(dp[l + 1][i][j], dp[l][i][j] + a[i][l - i + 1]);
            cmax(dp[l + 1][i + 1][j + 1], dp[l][i][j] + a[i + 1][l - i]);
        }
        else
        {
            cmax(dp[l + 1][i][j], dp[l][i][j] + a[i][l - i + 1] + a[j][l - j + 1]);
            cmax(dp[l + 1][i + 1][j + 1], dp[l][i][j] + a[i + 1][l - i] + a[j + 1][l - j]);
        }
        cmax(dp[l + 1][i][j + 1], dp[l][i][j] + a[i][l - i + 1] + a[j + 1][l - j]);
        if(i + 1 != j) cmax(dp[l + 1][i + 1][j], dp[l][i][j] + a[i + 1][l - i] + a[j][l - j + 1]);
        else cmax(dp[l + 1][i + 1][j], dp[l][i][j] + a[i + 1][l - i]);
    }
    printf("%d\n",dp[n + m][n][n]);
}
