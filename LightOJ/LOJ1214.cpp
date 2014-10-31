#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define LL long long

int main(){
    int tt;
    scanf("%d",&tt);
    char str[2000];
    LL ans;
    LL x;
    for(int t=1;t<=tt;t++){
        scanf("%s%lld",&str,&x);
        if(str[0] == '-') str[0] = '0';
        ans = (str[0] - '0') % x;
        //cout << ans <<endl;
        for(int i = 1; i < strlen(str);i++)
            ans = (ans * 10 + str[i] - '0') % x;
        if(ans == 0)printf("Case %d: divisible\n",t);
        else printf("Case %d: not divisible\n",t);
    }
    return 0;
}
