#include <stdio.h>
#include <string.h>
#include <algorithm>
char str[105];
int dp[105][105];
int main()
{
    while(scanf("%s",str) != EOF)
    {
        int n = strlen(str);
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int l = 1; l < n; l++)
        {
            for(int i = 0; i < n; i++)
            {
                int j = i + l;
                if(j >= n) break;
                dp[i][j] = dp[i + 1][j] + 1;
                for(int k = i + 1; k <= j; k++)
                    if(str[k] == str[i])
                        dp[i][j] = std::min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                //printf("%d %d %d\n", i, j, dp[i][j]);
            }
        }
        printf("%d\n",dp[0][n - 1]);
    }
}
