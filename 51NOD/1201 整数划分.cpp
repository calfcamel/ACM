#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define clr(a,b) memset(a,b,sizeof(a))
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)

const long long MOD = 1000000000 + 7;

long long dp[2][100005];

typedef std::pair<int, int> pii;
typedef std::pair<pii, int> piii;

#define MP3(x,y,z) std::make_pair(std::make_pair(x,y),z)
#define MP(x,y) std::make_pair(x,y)
#define PB(x) push_back(x)
#define all(x) x.begin(),x.end()
#define AA first
#define X first.first
#define Y first.second
#define BB second
long long ans;
int sum[501];
int n;
void gao()
{
    sum[0] = 0;
    FORR(i,500)
        sum[i] = sum[i - 1] + i;
    int m = 1;
    int cur = 0;
    FORR(i,n)
    {
         dp[cur][i] = 1;
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int m = 2; m <= 500; m++)
    {
        for(int i = sum[m]; i <= n; i++)
        {
            dp[cur ^ 1][i] = dp[cur][i - m];
            if(i - m >= sum[m])
                dp[cur ^ 1][i] += dp[cur ^ 1][i - m];
            while(dp[cur ^ 1][i] >= MOD)
                dp[cur ^ 1][i] -= MOD;
            if(i == n)
            {
                ans += dp[cur ^ 1][i];
                while(ans > MOD) ans -= MOD;
            }
        }
        cur ^= 1;
    }
}
int main()
{
    int T;
    scanf("%d",&n);
    ans = 1;
    gao();
    printf("%lld\n",ans);
}
