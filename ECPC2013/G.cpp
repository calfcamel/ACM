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
int dp[600][600][6];
int ii,jj,kk;
int dfs(int i, int j, int k,int num)
{
    FOR(nnn, 2 * num)
        printf(" ");
    printf("%d %d %d",i,j,k);
    if(~dp[i][j][k]) printf(" = %d\n", dp[i][j][k]);
    if(~dp[i][j][k])
        return dp[i][j][k];
    printf("::\n");
    int x = 1;
    if(j > 0)
    {
        jj = j - 1;
        kk = k + 1;
        ii = i;
        if(kk == 3) {kk -= 3; ii++;}
        x &= dfs(ii,jj,kk,num + 1);
    }
    if(i > 1)
    {
        ii = i - 1;
        jj = j;
        kk = k + 1;
        if(kk == 3) {kk -= 3; ii++;}
        x &= dfs(ii,jj,kk,num + 1);
        ii = i - 1;
        jj = j + 1;
        kk = k + 1;
        if(kk == 3) {kk -= 3; ii++;}
        x &= dfs(ii,jj,kk,num + 1);
    }
    printf("ED");
    FOR(nnn, 2 * num - 2)
        printf(" ");
    printf("%d %d %d",i,j,k);
    printf(" = %d\n", x ^ 1);
    return dp[i][j][k] = x ^ 1;
}
int main()
{
    clr(dp, -1);
    dp[1][0][1] = 0;
    dp[1][0][0] = 0;
    dp[1][0][2] = 0;
    int n;
    while(scanf("%d",&n))
    {
        printf("%d\n", dfs(n,0,0,1));
    }
    return 0;
}
