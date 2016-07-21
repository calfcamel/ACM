#include <stdio.h>
#include <algorithm>
#include <string.h>

int n;
long long m;
long long a[21][21];
const int HASH = 10007;
const int STATE = 1000000;

struct node
{
    int h[HASH], st[STATE], nxt[STATE], tot;
    long long dp[STATE];
    void init()
    {
        tot = 0;
        memset(h, -1, sizeof h);
    }
    void push(int s, long long f)
    {
        //printf("PUSH %d %lld\n", s, f);
        int p = s % HASH;
        for(int i = h[p]; ~i; i = nxt[i])
            if(st[i] == s)
            {
                dp[i] = (dp[i] + f) % m;
                return;
            }
        st[tot] = s;
        dp[tot] = f;
        nxt[tot] = h[p];
        h[p] = tot++;
    }
}hm[2];
int main()
{
    scanf("%d%lld",&n,&m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lld",&a[i][j]);
    int cur = 0;
    hm[cur].init();
    hm[cur].push(0,1);
    for(int i = 0; i < n; i++)
    {
        hm[cur ^ 1].init();
        for(int j = 0; j < hm[cur].tot; j++)
        {
            for(int k = 0; k < n; k++)
                if(((hm[cur].st[j]) & (1 << k)) == 0)
                {
                    hm[cur ^ 1].push(hm[cur].st[j] | (1 << k), hm[cur].dp[j] * a[i][k] % m);
                }
        }
        cur ^= 1;
    }
    printf("%lld\n", hm[cur].dp[0]);
    return 0;
}
