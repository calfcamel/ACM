#include <stdio.h>
#include <string.h>

int u[505][505];
int l[505][505];
char str[505][505];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
        scanf("%s",str[i]);
    memset(u,0,sizeof u);
    memset(l,0,sizeof l);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            u[i][j] = u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
            l[i][j] = l[i - 1][j] + l[i][j - 1] - l[i - 1][j - 1];
            if(i > 1 && str[i - 2][j - 1] == '.' && '.' == str[i - 1][j - 1]) u[i][j]++;
            if(j > 1 && str[i - 1][j - 2] == '.' && '.' == str[i - 1][j - 1]) l[i][j]++;
        }
    int q;
    scanf("%d",&q);
    int x1,x2,y1,y2;
    int ans;
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d",&x1,&y1);
        scanf("%d%d",&x2,&y2);
        ans = 0;
        x1++;
        if(x1 <= x2 && y1 <= y2)
            ans += u[x2][y2] - u[x1 - 1][y2] - u[x2][y1 - 1] + u[x1 - 1][y1 - 1];
        x1--;y1++;
        if(x1 <= x2 && y1 <= y2)
            ans += l[x2][y2] - l[x1 - 1][y2] - l[x2][y1 - 1] + l[x1 - 1][y1 - 1];
        printf("%d\n",ans);
    }
    return 0;
}
