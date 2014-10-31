#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define LL long long

int main(){
    int tt;
    scanf("%d",&tt);
    LL x,y;
    int ans;
    int s;
    LL n;
    for(int t=1;t<=tt;t++){
        scanf("%lld",&n);
        x = n;
        y = 1;
        while(x % 2 == 0){
            x /= 2;
            y *= 2;
        }
        if(n & 1) printf("Case %d: Impossible\n",t);
        else printf("Case %d: %lld %lld\n",t,x,y);
    }
    return 0;
}
