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
#define eps 1e-16
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
bool zero(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zero(x))
        return 0;
    if(x>0)
        return 1;
    return -1;
}
bool check(long long l,long long d,long long r)
{
    if(l*d*r-(d*r+l*r+l*d)*100000>0)
        return true;
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        puts("hi");
        double l,d,r;
        scanf("%lf%lf%lf",&l,&d,&r);
        long long L,D,R;
        L=(long long)(l*100000);
        D=(long long)(d*100000);
        R=(long long)(r*100000);
        printf("%lld %lld %lld\n",L,D,R);
        printf("%lld\n",L*D*R);
        int flag=0;
        flag|=check(L,D,R);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
