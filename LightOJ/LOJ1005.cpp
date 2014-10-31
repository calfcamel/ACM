#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#define LL long long

LL gcd(LL a, LL b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
LL a[31];
inline void init(){
    for(int i = 0; i <= 30; i++)
        a[i] = i;
}
int main(){
    int tt;
    scanf("%d",&tt);
    LL ans;
    LL n;
    LL k;
    LL g;
    LL s;
    for(int t=1;t<=tt;t++){
        scanf("%lld%lld",&n,&k);
        if(k>n) ans = 0;
        else{
            ans = 1;
            init();
            for(int i = 0; i < k; i++){
                s = (n - i) * (n - i);
                for(int j = 1; j <= k; j++){
                    g = gcd(s , a[j]);
                    s = s / g;
                    a[j] = a[j] / g;
                }
                ans = ans * s;
            }
        }
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
