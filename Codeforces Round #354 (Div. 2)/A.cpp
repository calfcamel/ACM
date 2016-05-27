#include <stdio.h>

int a[200];
int main()
{
    int n;
    scanf("%d",&n);
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] == 1 || a[i] == n)
        {
            if(i - 1 >= ans)
                ans = i - 1;
            if(n - i >= ans)
                ans = n - i;
        }
    }
    printf("%d\n",ans);;
}
