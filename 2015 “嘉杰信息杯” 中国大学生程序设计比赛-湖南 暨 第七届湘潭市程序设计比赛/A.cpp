#include <stdio.h>
#include <string.h>

long long sum[2][2],sum1,sum0;
long long dp[1000006][2][2];
int n,m;

const long long MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)


int getans(int n, int m)
{
    clr(dp,0);
    clr(sum,0);
    sum[1][0] = 1;
    sum1 = 0;
    sum0 = 1;
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    if(m == 1)
    {
        sum0--;
        sum1++;
    }
    FORR(i,n)
    {
        dp[i][0][0] += sum[1][0];
        dp[i][0][1] += sum[1][1];
        dp[i][1][1] += sum[0][1];
        dp[i][1][1] += sum1;
        dp[i][1][0] += sum0;
        FOR(j,2) FOR(k,2)
            while(dp[i][j][k] >= MOD) dp[i][j][k] -= MOD;
        sum[1][0] += dp[i][1][0];
        sum[1][1] += dp[i][1][1];
        sum[0][1] += dp[i][0][1];
        if(i - m + 1 >= 0) sum1 += dp[i - m + 1][0][0];
        sum0 += dp[i][0][0];
        if(i - m + 1 >= 0) sum0 -= dp[i - m + 1][0][0];
        sum0 += MOD;
        FOR(j,2) FOR(k,2)
            while(sum[j][k] >= MOD) sum[j][k] -= MOD;
        while(sum0 >= MOD) sum0 -= MOD;
        while(sum1 >= MOD) sum1 -= MOD;
    }
    return (dp[n][0][1] + dp[n][1][1]) % MOD;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n", getans(n,m));
    }
}
