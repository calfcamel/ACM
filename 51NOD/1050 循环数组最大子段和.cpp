#include <stdio.h>
#include <algorithm>

#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__; i++)
#define REP(i,y,x) for(int i = (int)(y), __END__ = (int)(x); i <= __END__; i++)
int n;
long long a;
long long dp;
long long ans;
long long sum;
long long dp0;
long long ans0;
int main()
{
    scanf("%d",&n);
    dp = 0;
    sum = 0;
    int flag = 1;
    FOR(i,n)
    {
        scanf("%lld",&a);
        if(!i)
            ans = a;
        if(!i)
            dp = a;
        if(!i)
            ans0 = a;
        if(!i)
            dp0 = a;
        if(a < 0)
            flag = 0;
        sum += a;
        if(i)
        {
            dp = std::min(a, dp + a);
            ans = std::min(ans,dp);
            dp0 = std::max(a, dp0 + a);
            ans0 = std::max(ans0,dp0);
        }
    }
    //printf("ans = %lld ans0 = %lld sum = %lld\n", ans, ans0, sum);
    if(flag)
        ans = sum;
    else
        ans = sum - ans;
    ans = std::max(ans0,ans);
    printf("%lld\n",ans);
}
