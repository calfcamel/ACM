#include <stdio.h>
#include <queue>
const int MAXN = 500000 + 5;

int dp[MAXN];
int q[MAXN];
int sum[MAXN];
int n;
int m;
int head,tail;

inline int getdp(int i, int j)
{
    return dp[j] + m + (sum[i] - sum[j]) * (sum[i] - sum[j]);
}
inline int getup(int j, int k)
{
    return dp[j] + sum[j] * sum[j] - dp[k] - sum[k] * sum[k];
}
inline int getdown(int j, int k)
{
    return 2 * (sum[j] - sum[k]);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&sum[i]);
            sum[i] += sum[i - 1];
        }
        dp[0] = 0;
        head = tail = 0;
        q[tail++] = 0;
        for (int i = 1; i <= n; ++i)
        {
            while(head + 1 < tail && getup(q[head + 1], q[head]) <= sum[i] * getdown(q[head + 1], q[head])) head++;
            dp[i] = getdp(i, q[head]);
            while(head + 1 < tail && getup(i, q[tail - 1]) * getdown(q[tail - 1], q[tail - 2]) <= getup(q[tail - 1], q[tail - 2]) * getdown(i, q[tail - 1])) tail--;
            q[tail++] = i;
        }
        printf("%d\n", dp[n]);
    }
}
