#include <stdio.h>
#include <string.h>
#include <algorithm>
int st[60];
int dp[2][60][60];
char str[20];
int main()
{
    int tot = 0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int mask = 0; mask < (1 << m); mask++)
    {
        int flag = 1;
        for(int i = 0; i < 10; i++)
            if(mask & (1 << i))
                if((mask & (1 << (i + 1))) || (mask & (1 << (i + 2))))
                    flag = false;
        if(flag) st[tot++] = mask;
        /*
        if(flag)
        {
            for(int i = 0; i < 10; i++)
                printf("%d", (mask & (1 << i)) >> i);
            puts("");
        }
        */
    }
    //printf("%d\n",tot);
    //tot = 60;
    memset(dp,0,sizeof dp);
    int cur = 0;
    int ans = 0;
    for(int l = 0; l < n; l++)
    {
        scanf("%s",str);
        int d;
        for(int i = 0; i < m; i++)
        {
            int x = 0;
            if(str[i] == 'H') x = 1;
            d <<= 1;
            d |= x;
        }
        memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
        for(int i = 0; i < tot; i++) if(!(st[i] & d))
            for(int j = 0; j < tot; j++) if(!(st[i] & st[j]))
                for(int k = 0; k < tot; k++) if(!(st[i] & st[k])) if(!(st[j] & st[k]))
                {
                    dp[cur ^ 1][k][i] = std::max(dp[cur ^ 1][k][i], dp[cur][j][k] + __builtin_popcount(st[i]));
                    ans = std::max(ans, dp[cur ^ 1][k][i]);
                }
        cur ^= 1;
    }
    printf("%d\n",ans);
}
