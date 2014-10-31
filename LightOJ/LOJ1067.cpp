#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#define LL long long
const LL MOD = 1000003;
const LL MAXN = 1000000;

LL mul(LL a,LL b){return (a * b) % MOD;}
LL add(LL a,LL b){return (a + b) % MOD;}

LL inv[MAXN + 1];
LL mulinv[MAXN + 1];
LL muln[MAXN + 1];
void pre(){
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i <= MAXN; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
void pre2(){
    mulinv[0] = 1;
    muln[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        mulinv[i] = mul(mulinv[i - 1] , inv[i]);
        muln[i] = mul(muln[i - 1] , i);
    }
}
int main(){
    int tt;
    scanf("%d",&tt);
    LL ans;
    LL n,m;
    pre();
    pre2();
    for(int t=1;t<=tt;t++){
        scanf("%lld%lld",&n,&m);
        ans = mul(muln[n] , mulinv[m]);
        ans = mul(ans , mulinv[n - m]);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
