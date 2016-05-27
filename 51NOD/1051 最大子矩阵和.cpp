#include <stdio.h>
#include <algorithm>

#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__; i++)
#define REP(i,y,x) for(int i = (int)(y), __END__ = (int)(x); i <= __END__; i++)
int a[505][505];
long long dp[505];
long long sum[505][505];
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    FORR(i,n) FORR(j,m)
        scanf("%d",&a[i][j]);
    FORR(i,n)
    {
        sum[i][0] = 0;
        FORR(j,m)
            sum[i][j] = sum[i][j - 1] + a[i][j];
    }
    long long ans = -99999999900000000LL;
    FORR(l,m) REP(r, l, m)
    {
        dp[0] = 0;
        FORR(j,n)
            dp[j] = std::max(sum[j][r] - sum[j][l - 1], dp[j - 1] + sum[j][r] - sum[j][l - 1]);
        FORR(j,n)
            ans = std::max(dp[j],ans);
    }
    printf("%lld\n",ans);
}
