#include <stdio.h>
#include <string.h>

int a[105];
char s[105];
int n;
int d;
int ans;

int main()
{
    a[0] = 1;
    scanf("%d%d",&d,&n);
    for(int i = 1; i <= n; i++)
    {
        a[i] = 1;
        scanf("%s",s);
        for(int j = 0; j < d; j++)
        {
            a[i] &= s[j] - '0';
        }
    }
    int now = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0) now++;
        else now = 0;
        if(now > ans)
            ans = now;
    }
    printf ("%d",ans);
}
