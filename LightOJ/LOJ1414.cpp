#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define LL long long
int is12(char* s){
    if(s[0]=='J'&&s[1]=='a') return 1;
    if(s[0]=='F')return 1;
    return 0;
}
int getans(int y){
    if(y%100==0&&y%400!=0) return 0;
    if(y%4==0) return 1;
    return 0;
}
int main(){
    int tt;
    scanf("%d",&tt);
    char bm[20];
    char em[20];
    int ans;
    int bd,by,ed,ey;
    for(int t=1;t<=tt;t++){
        scanf("%s %d, %d",&bm,&bd,&by);
        scanf("%s %d, %d",&em,&ed,&ey);
        ans = 0;
        if(is12(bm)) ans += getans(by);
        if(by!=ey){
            if(!is12(bm)) ans += getans(ey);
            else{
                if(em[0]=='F'&&ed==29) ans++;
            }
        }
        if(ey - by <=7000)
            for(int i=by+1;i<ey;i++)
                ans += getans(i);
        else{
            int i;
            for(i=by+1;(i+1)%2000!=0;i++)
                ans += getans(i);
            for(;(i+2000<ey);i+=2000)
                ans += 486;
            for(i=i+1;i<ey;i++)
                ans += getans(i);
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
