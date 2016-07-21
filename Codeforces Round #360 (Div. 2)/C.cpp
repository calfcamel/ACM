#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct edge
{
    int nxt;
    int v;
}e[200005];
const int MAXN = 200005;
int vis[MAXN];
int jh[MAXN];
int h[MAXN];
int tot = 0;
void add(int v, int u)
{
    e[tot].v = v;
    e[tot].nxt = h[u];
    h[u] = tot++;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof vis);
    memset(jh,0,sizeof jh);
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    std::queue<int> Q;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            Q.push(i);
            jh[i] = 1;
            vis[i] = 1;
        }
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            int t = h[u];
            while(~t)
            {
                if(!vis[e[t].v])
                {
                    vis[e[t].v] = 1;
                    Q.push(e[t].v);
                }
                if(jh[e[t].v] == 0)
                {
                    jh[e[t].v] = ((jh[u] - 1) ^ 1) + 1;
                }
                else if(jh[e[t].v] != ((jh[u] - 1) ^ 1) + 1)
                {
                    puts("-1");
                    return 0;
                }
                t = e[t].nxt;
            }
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1; i <= n; i++)
        if(jh[i] == 1) sum1++;else sum2++;
    printf("%d\n",sum1);
    int flag = 1;
    for(int i = 1; i <= n; i++) if(jh[i] == 1)
    {
        if(flag) flag = 0; else printf(" ");
        printf("%d",i);
    }
    puts("");
    printf("%d\n",sum2);
    flag = 1;
    for(int i = 1; i <= n; i++) if(jh[i] == 2)
    {
        if(flag) flag = 0; else printf(" ");
        printf("%d",i);
    }
    puts("");
}
