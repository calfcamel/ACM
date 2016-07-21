#include <stdio.h>

int a[100];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum ^= a[i];
        int ans = 0;
        if(sum) for(int i = 0; i < n; i++)
            if(a[i] > (a[i] ^ sum))
                ans++;

        printf("%d\n", ans);
        //printf("sum = %d ans = %d\n", sum, ans);
    }
}
