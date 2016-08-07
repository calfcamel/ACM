#include <stdio.h>
#include <string.h>
#include <algorithm>
long long dp[2][1 << 10];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        if(m > n) std::swap(n,m);
        memset(dp,0,sizeof dp);
        int cur = 0;
        dp[cur][0] = 1;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        {
            memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
            for(int mask = 0; mask < (1 << m); mask++)
            {
                if(mask & (1 << j)) dp[cur ^ 1][mask ^ (1 << j)] += dp[cur][mask];
                if(j + 1 < m && !(mask & (1 << j)) && !(mask & (1 << (j + 1)))) dp[cur ^ 1][mask ^ (1 << (j + 1))] += dp[cur][mask];
                if(!(mask & (1 << j))) dp[cur ^ 1][mask ^ (1 << j)] += dp[cur][mask];
            }
            cur ^= 1;
        }
        printf("%lld\n", dp[cur][0]);
    }
}
