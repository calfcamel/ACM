#include <stdio.h>
#include <set>

typedef long long LL;

int n;
const int MAXN = 100005;
LL dp[MAXN];
int a[MAXN];
int q[MAXN];
int head,tail;
LL m,sum;
std::multiset<int> S;

int main()
{
    scanf("%d%lld",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    head = tail = 0;
    int low = 1;
    sum = 0;
    for(int i = 1; i <= n; i++)
    {
        //printf("running %d...\n", i);
        sum += a[i];
        while(sum > m) sum -= a[low++];
        if(low > i)
        {
            puts("-1");
            return 0;
        }
        while(head < tail && a[i] > a[q[tail - 1]])
        {
            if(tail - 1 > head)
                S.erase(dp[q[tail - 2]] + a[q[tail - 1]]);
            tail--;
        }
        q[tail++] = i;
        if(tail - 1> head)
            S.insert(dp[q[tail - 2]] + a[q[tail - 1]]);
        while(q[head] < low)
        {
            if(tail - 1 > head)
                S.erase(dp[q[head]] + a[q[head + 1]]);
            head++;
        }
        LL tmp = *(S.begin());
        dp[i] = dp[low - 1] + a[q[head]];
        if(head < tail - 1 && tmp < dp[i])
            dp[i] = tmp;
    }
    printf("%lld",dp[n]);
    return 0;
}
