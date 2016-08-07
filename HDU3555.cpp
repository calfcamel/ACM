#include <stdio.h>
#include <string.h>
int m;
int a[70];
long long dp[70][2][10];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        m = 0;
        long long nn = n;
        while(nn)
        {
            a[m++] = nn % 10;
            nn /= 10;
        }
        memset(dp, -1, sizeof dp);
        dp[m][0][9] = 1;
        for(int i = m - 1; i >= 0; i--)
            for(int flag = 0; flag < 2; flag++)
                for(int last = 0; last < 10; last++)
                    if(~dp[i + 1][flag][last])
                    {
                        for(int j = 0; j < 10; j++)
                        {
                            if(last == 4 && j == 9) continue;
                            if(flag == 0 && j > a[i]) break;
                            if(flag == 0 && j == a[i])
                            {
                                if(~dp[i][flag][j])
                                    dp[i][flag][j] += dp[i + 1][flag][last];
                                else
                                    dp[i][flag][j] = dp[i + 1][flag][last];
                                continue;
                            }
                            if(dp[i][1][j] != -1)
                                dp[i][1][j] += dp[i + 1][flag][last];
                            else
                                dp[i][1][j] = dp[i + 1][flag][last];
                        }
                    }
        long long ans = 0;
        for(int flag = 0; flag < 2; flag++)
            for(int last = 0; last < 10; last++)
                if(~dp[0][flag][last]){
                    ans += dp[0][flag][last];}
        printf("%lld\n", n - ans + 1);
    }
}
