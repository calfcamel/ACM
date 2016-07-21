#include <stdio.h>
#include <algorithm>
#include <string.h>
char inp[5];
inline int getinput()
{
    scanf("%s", inp);
    int ret = 27;
    if(inp[1] == 'm') ret = 0;
    if(inp[1] == 's') ret = 9;
    if(inp[1] == 'p') ret = 18;
    ret += inp[0] - '0';
    return ret;
}

inline void output(int x)
{
    char ch = 'm';
    if(x > 27) {x -= 27; ch = 'c';}
    if(x > 18) {x -= 18; ch = 'p';}
    if(x > 9) {x -= 9; ch = 's';}
    printf(" %d%c", x, ch);
}

int a[15];
int c[15];
int b[35];
int ans[30];
int tot;
const int chk2[13] = {1,9,10,18,19,27,28,29,30,31,32,33,34};

int vis[35];
int dfsret;
void dfs(int i, int jiang)
{
    if(dfsret)
        return;
    if(i == 14)
    {
        if(jiang) dfsret = 1;
        return;
    }
    if(vis[c[i]] < 0)
    {
        vis[c[i]]++;
        dfs(i + 1, jiang);
        vis[c[i]]--;
    }
    if(jiang == 0 && b[c[i]] >= 2)
    {
        b[c[i]] -= 2;
        vis[c[i]] -= 1;
        dfs(i + 1, 1);
        vis[c[i]] += 1;
        b[c[i]] += 2;
    }
    if(b[c[i]] >= 3)
    {
        b[c[i]] -= 3;
        vis[c[i]] -= 2;
        dfs(i + 1, jiang);
        b[c[i]] += 3;
        vis[c[i]] += 2;
    }
    if(c[i] <= 27)
    {
        int x = (c[i] - 1) % 9 + 1;
        if(x <= 7 && b[c[i]] && b[c[i] + 1] && b[c[i] + 2])
        {
            b[c[i]] --;
            b[c[i] + 1]--;
            vis[c[i] + 1]--;
            b[c[i] + 2]--;
            vis[c[i] + 2]--;
            dfs(i + 1, jiang);
            b[c[i]] ++;
            b[c[i] + 1]++;
            vis[c[i] + 1]++;
            b[c[i] + 2]++;
            vis[c[i] + 2]++;
        }
    }
}
int check()
{
    int sum = 0;
    for(int i = 1; i <= 34; i++)
        if(b[i] >= 2) sum++;
    if(sum == 7)
        return 1;

    int flag1 = 1;
    int flag2 = 0;
    for(int i = 0; i < 13; i++)
    {
        if(b[chk2[i]] == 0) flag1 = 0;
        if(b[chk2[i]] == 2) flag2 = 1;
    }
    if(flag1 & flag2)
        return 1;

    for(int i = 0; i < 14; i++)
        c[i] = a[i];
    dfsret = 0;
    std::sort(c, c + 14);
    dfs(0,0);
    return dfsret;
}
int main()
{
    int T;
    for(int i = 0; i < 35; i++)
        vis[i] = b[i] = 0;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        for(int i = 0; i < 13; i++)
            a[i] = getinput();
        for(int i = 0; i < 35; i++) b[i] = 0;
        for(int i = 0; i < 13; i++) b[a[i]]++;
        tot = 0;
        for(int i = 1; i <= 34; i++)
        {
            a[13] = i;
            b[i]++;
            if(b[i] <= 4 && check())
            {
                ans[tot++] = i;
            }
            b[i]--;
        }
        if(tot)
        {
            printf("%d",tot);
            std::sort(ans, ans + tot);
            for(int i = 0; i < tot; i++)
                output(ans[i]);
            puts("");
        }
        else puts("Nooten");
    }
}
