#include <stdio.h>
#include <queue>
const int MAXN = 1000000 + 5;

long long dp[MAXN];
int q[MAXN];
long long a[MAXN];
long long d[MAXN];
int n;
int m;
int head,tail;

inline long long getdp(int i, int j)
{
    int ret = dp[j] - d[j] * (i - j);
    if(ret < 0)
        ret = 0;
    return ret + a[i];
}
inline long long getup(int j, int k)
{
    return dp[j] + d[j] * j - (dp[k] + d[k] * k);
}
inline long long getdown(int j, int k)
{
    return d[j] - d[k];
}
int main()
{
    while(~scanf("%d",&n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld",&a[i],&d[i]);
        }
        a[n + 1] = 0;
        dp[0] = 0;
        head = tail = 0;
        q[tail++] = 0;
        for (int i = 1; i <= n + 1; ++i)
        {
            while(head + 1 < tail && getup(q[head + 1], q[head]) >= i * getdown(q[head + 1], q[head])) head++;
            dp[i] = getdp(i, q[head]);
            printf("dp[%d] = %lld  q[head] = %d\n",i, dp[i],q[head]);
            while(head + 1 < tail && getup(i, q[tail - 1]) * getdown(q[tail - 1], q[tail - 2]) >= getup(q[tail - 1], q[tail - 2]) * getdown(i, q[tail - 1])) tail--;
            q[tail++] = i;
        }
        printf("%lld\n", dp[n + 1]);
    }
}
