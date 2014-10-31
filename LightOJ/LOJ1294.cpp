#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define LL long long

int main(){
    int tt;
    scanf("%d",&tt);
    LL x,y;
    LL ans;
    int s;
    for(int t=1;t<=tt;t++){
        scanf("%lld%lld",&x,&y);
        ans = x / 2 * y;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
