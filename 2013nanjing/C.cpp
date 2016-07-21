#include <stdio.h>
#include <string.h>
#define clr(a,b) memset(a,b,sizeof(a))
const int HASH = 10007;
const int STATE = 1024 * 20;
const long long MOD = 1000000007;
struct HASHMAP
{
    int head[HASH],next[STATE],size;
    int state[STATE];
    long long f[STATE];
    void init()
    {
        size = 0;
        clr(head, -1);
    }
    void push(int p, int q, long long ans)
    {
        //printf("\tpush %d %d %lld\n",p,q,ans);
        ans %= MOD;
        if(q > 20) return;
        int st = p * 100 + q;
        int i,h = st % HASH;
        for(i = head[h]; ~i; i = next[i])
            if(state[i] == st)
            {
                f[i] += ans;
                f[i] %= MOD;
                return;
            }
        state[size] = st;
        f[size] = ans;
        next[size] = head[h];
        head[h] = size++;
    }
}hm[3];
int a[105][10];
char str[20];
int main()
{
    int n,m,c,d;
    while(scanf("%d%d%d%d",&n,&m,&c,&d) == 4)
    {
        for(int j = 0; j < m; j++)
            a[0][j] = 0;
        for(int j = 0; j < m; j++)
            a[n + 1][j] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%s",str);
            for(int j = 0; j < m; j++)
                a[i][j] = str[j] - '0';
        }
        int mask, cnt;
        int cur = 0;
        hm[cur].init();
        hm[1].init();
        hm[2].init();
        hm[cur].push(a[1][0], 0, 1);
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //printf("%d %d:\n", i,j);
                if(i == 0 && j == 0)
                    continue;
                //hm[(cur + 1) % 3].init();
                for(int k = 0; k < hm[cur].size; k++)
                {
                    mask = hm[cur].state[k] / 100;
                    cnt = hm[cur].state[k] % 100;
                    //printf("  now %d %d\n",mask,cnt);
                    if((mask & (1 << j)) == 0)
                    {
                        hm[(cur + 1) % 3].push(mask | (a[i + 1][j] << j), cnt, hm[cur].f[k]);
                    }
                    else
                    {
                        mask &= ~(1 << j);
                        hm[(cur + 1) % 3].push(mask | (a[i + 1][j] << j), cnt + 1, hm[cur].f[k]);
                        if(j + 1 < m) if(mask & (1 << (j + 1)))
                        {
                            hm[(cur + 2) % 3].push((mask & ~(1 << (j + 1))) | (a[i + 1][j] << j) | (a[i + 1][j + 1] << (j + 1)), cnt, hm[cur].f[k]);
                        }
                        if(a[i + 1][j])
                        {
                            hm[(cur + 1) % 3].push(mask, cnt, hm[cur].f[k]);
                        }
                    }
                }
                hm[cur].init();
                cur = (cur + 1) % 3;
            }
        }
        long long ans = 0;
        for(int k = 0; k < hm[cur].size; k++)
        {
            mask = hm[cur].state[k] / 100;
            if(mask != 0) continue;
            cnt = hm[cur].state[k] % 100;
            if(cnt >= c && cnt <= d)
                ans += hm[cur].f[k];
            ans %= MOD;
        }
        printf("%lld\n",ans);
    }
}
