#include <stdio.h>
#include <string.h>


int a[505];
int dp[2][505][505];
int n,t;
int main()
{
    memset(dp,0,sizeof dp);
    scanf("%d%d",&n,&t);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int cur = 0;
    dp[cur][0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= t; j++)
            for(int k = 0; k <= t; k++)
                if(dp[cur][j][k])
                    dp[cur ^ 1][j][k] = 1;
        for(int j = t; j >= a[i]; j--)
            for(int k = 0; k <= t; k++)
            {
                if(dp[cur][j - a[i]][k]) dp[cur ^ 1][j][k] = 1;
                if(dp[cur][k][j - a[i]]) dp[cur ^ 1][k][j] = 1;
            }
        cur ^= 1;
    }
    int sum = 0;
    for(int i = 0; i <= t; i++)
        if(dp[cur][i][t - i] || dp[cur][t - i][i]) sum++;
    printf("%d\n", sum);
    for(int i = 0; i <= t; i++)
        if(dp[cur][i][t-i] || dp[cur][t-i][i])
        {
            printf("%d ", i);
        }
}
