#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-14
const long long mod=110119;
long long inv[120000];
long long fac[120000];
long long ifac[120000];
void init()
{
    inv[0]=fac[0]=ifac[0]=1;
    inv[1]=fac[1]=ifac[1]=1;
    for(int i=2; i<mod; i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
long long C(long long n,long long m)
{
    if(m>n)return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
long long lucas(long long n,long long m)
{
    if(n<0)return 0;
    if(m>n)return 0;
    if(m==0)return 1;
    return lucas(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}
bool check(long long x,long long y)
{
    return true;
    if(x*2-y<0)return false;
    if(y*2-y<0)return false;
    if(((x*2-y)%3==0)&&((y*2-x)%3==0))
        return true;
    return false;
}
long long dp[202];
pair<long long,long long>pr[202];
int main()
{
    init();
    int cas=0;
    long long n,m;
    int r;
    while(scanf("%lld%lld%d",&n,&m,&r)!=EOF)
    {
//        printf("!\n");
        cas++;
        n--;
        m--;
        int tot=0;

        for(int i=0; i<r; i++)
        {
//            printf("%d\n",i);
            long long x,y;
            scanf("%lld%lld",&x,&y);
            x--;
            y--;
            if(check(x,y))
            {
                //pr[tot++]=make_pair((x*2-y)/3,(y*2-x)/3);
                pr[tot++] = make_pair(x,y);
            }
            else
                continue;
        }
//        printf("ha\n");
        if(check(n,m))
        {
            //pr[tot++]=make_pair((n*2-m)/3,(m*2-n)/3);
            pr[tot++] = make_pair(n,m);
        }
        else
        {
            printf("Case #%d: 0\n",cas);
            continue;
        }
        sort(pr,pr+tot);
//        for(int i=0;i<tot;i++)
//            printf("%I64d %I64d\n",pr[i].first,pr[i].second);
        for(int i=0; i<tot; i++)
        {
            dp[i]=lucas(pr[i].first+pr[i].second,pr[i].first);
            for(int j=0; j<i; j++)
            {
                if(pr[j].second>pr[i].second)continue;
                dp[i]-=(dp[j]*lucas(pr[i].first-pr[j].first+pr[i].second-pr[j].second,pr[i].first-pr[j].first))%mod;
                dp[i]=(dp[i]%mod+mod)%mod;
            }
        }
        printf("Case #%d: %lld\n",cas,dp[tot-1]);
    }
    return 0;
}
