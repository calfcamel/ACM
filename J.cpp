#include <stdio.h>

inline long long getans(long long a, long long b, long long c)
{
    long long std = 0;
    long long ret = 0;
    if(a > 0) {a--; ret += std; std++;}
    if(a > 0) {a--; ret += std; std++;}
    if(b > 0) {b--; ret += std; std++;}
    if(b > 0) {b--; ret += std; std++;}
    if(c > 0) {c--; ret += std; std++;}
    if(c > 0) {c--; ret += std; std++;}
    ret += std * (a + b + c);
    return ret;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c) != EOF)
    {
        printf("%lld\n", getans(a,b,c));
    }
    return 0;
}
