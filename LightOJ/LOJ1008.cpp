#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define LL long long

int main(){
    int tt;
    cin>>tt;
    LL n;
    LL x,y;
    LL p;
    LL s;
    for(int t=1;t<=tt;t++){
        cin>>n;
        p = sqrt(n);
        if(p * p < n) p ++;
        x = p;
        y = p;
        s = n - (p - 1) * (p - 1);
        if(p & 1){
            if(s<=p){
                y = s ;
            }
            else{
                x = 2 * p - 1 - s + 1;
            }
        }
        else{
            if(s>p){
                y = 2 * p - 1 - s + 1;
            }
            else{
                x = s;
            }

        }
        cout<<"Case "<<t<<": "<<x<<' '<<y<<endl;
    }
    return 0;
}
