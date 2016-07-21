#include<stdio.h>
#include<string.h>

const int HASH=100007;
const int STATE=2000006;
struct HASHMAP
{
    int head[HASH],next[STATE],size;
    long long state[STATE],f[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(long long st,long long ans)
    {
        int i,h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
            if(state[i]==st)
            {
                f[i]+=ans;
                return;
            }
        state[size]=st;
        f[size]=ans;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];
int main()
{
    int T;
    scanf("%d",&T);
    for(int CAS = 1; CAS <= T; CAS++)
    {
        int n, m;
        scanf("%d%d",&n,&m);
        int cur = 0;
        int x;
        hm[cur].init();
        hm[cur].push(0,1);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            hm[cur ^ 1].init();
            for(int i = 0; i < hm[cur].size; i++)
            {
                hm[cur ^ 1].push(hm[cur].state[i] ^ x, hm[cur].f[i]);
                hm[cur ^ 1].push(hm[cur].state[i], hm[cur].f[i]);
            }
            cur ^= 1;
        }
        long long ans = 0;
        for(int i = 0; i < hm[cur].size; i++)
            if(hm[cur].state[i] >= m)
                ans += hm[cur].f[i];
        printf("Case #%d: %lld\n",CAS,ans);
    }
}
