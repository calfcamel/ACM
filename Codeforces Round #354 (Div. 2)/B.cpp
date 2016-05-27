#include <stdio.h>
double a[30][30];
double eps = 1e-8;
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    a[1][1] = t;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            if(a[i][j] + eps >= 1.0)
            {
                ans ++;
                a[i + 1][j] += (a[i][j] - 1.0) / 2.0;
                a[i + 1][j + 1] += (a[i][j] - 1.0) / 2.0;
            }
    printf("%d\n",ans);
}
