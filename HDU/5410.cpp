#include <stdio.h>
#include <algorithm>
int w[2001];
int f[2001];
int g[2001];
int a[2001];
int b[2001];
int n,m;
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d%d",&m,&n);
        for(int i = 0; i < n; i++)
            scanf("%d%d%d",&w[i],&a[i],&b[i]);
        for(int i = 0; i <= m; i++)
            f[i] = -1;
        f[0] = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= m; j++) g[i] = -1;
            for(int j = 0; j <= m - w[i]; j++)
                if(~f[j]) g[j + w[i]] = f[j] + a[i] + b[i];
            for(int j = w[i]; j <= m - w[i]; j++)
                if(~g[j]) g[j + w[i]] = std::max(g[j + w[i]], g[j] + a[i]);
            for(int j = w[i]; j <= m; j++)
                f[j] = std::max(f[j], g[j]);
        }
        int ans = 0;
        for(int i = 0; i <= m; i++)
            ans = std::max(ans, f[i]);
        printf("%d\n", ans);
    }
}
