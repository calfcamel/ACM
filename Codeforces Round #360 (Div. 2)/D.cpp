#include <stdio.h>

long long gcd(long long a, long long b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

int n,x,tk;

int main()
{
    scanf("%d%d",&n,&tk);
    long long k = tk;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        k /= gcd(k, x);
    }
    if(k == 1)
        puts("Yes");
    else puts("No");
    return 0;
}
