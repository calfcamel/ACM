#include <stdio.h>
#include <algorithm>
#define cmin(x,y) x = std::min(x,y);
int dp[100005];
const int inf = 100005;
int main()
{
    for(int i = 0; i < inf; i++)
        dp[i] = inf;
    int a,b;
    scanf("%d%d",&a,&b);
    if(a > b)
    {
        puts("-1");
        return 0;
    }
    dp[a] = 0;
    for(int i = a; i < b; i++)
    {
        if(i + i <= b)
            cmin(dp[i + i], dp[i] + 1);
        for(int j = 1; j * j <= i; j++) if(i % j == 0)
        {
            if(i + j <= b) cmin(dp[i + j], dp[i] + 1);
            if(i + i / j <= b) cmin(dp[i + i / j], dp[i] + 1);
        }
    }
    printf("%d\n",dp[b]);
    return 0;
}
