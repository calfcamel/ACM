#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#define LL long long
LL abs(LL x){
    if(x < 0) return -x;
    return x;
}
LL gcd(LL a, LL b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main(){
    int tt;
    scanf("%d",&tt);
    LL ans;
    LL x;
    LL y;
    LL a;
    LL b;
    for(int t=1;t<=tt;t++){
        scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
        ans = gcd(abs(x - a) , abs(y - b)) + 1;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
