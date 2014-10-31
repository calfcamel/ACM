#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define LL long long

int main(){
    int tt;
    scanf("%d",&tt);
    int x,y;
    int ans;
    int s;
    for(int t=1;t<=tt;t++){
        scanf("%d%d",&x,&y);
        s = x * y;
        ans = (s >> 1) + (s & 1);
//        cout<<"Case "<<t<<": "<<ans<<endl;
        if(x == 1) ans = y;
        if(y == 1) ans = x;
        if(x == 2) ans = ( y / 4 * 2 + min(y % 4, 2)) * 2;
        if(y == 2) ans = ( x / 4 * 2 + min(x % 4, 2)) * 2;
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
