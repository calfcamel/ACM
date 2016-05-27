#include <stdio.h>
int n,k;
int ans;
char str[100005];
int pre[100005];
int nxt[100005];
int main()
{
    scanf("%d%d%s",&n,&k,str);
    ans = k;
    int r = 0;
    int cnt = 0;
    for(int l = 0; l < n; l++)
    {
        while((cnt < k && r < n) || (r < n && cnt == k && str[r] == 'a'))
        {
            if(str[r] == 'b')
                cnt++;
            r++;
        }
        if(str[l] == 'b')
            cnt--;
        if(r - l > ans)
            ans = r - l;
    }
    r = 0;
    cnt = 0;
    for(int l = 0; l < n; l++)
    {
        while((cnt < k && r < n) || (r < n && cnt == k && str[r] == 'b'))
        {
            if(str[r] == 'a')
                cnt++;
            r++;
        }
        if(str[l] == 'a')
            cnt--;
        if(r - l > ans)
            ans = r - l;
    }
    printf("%d\n",ans);
    return 0;
}
