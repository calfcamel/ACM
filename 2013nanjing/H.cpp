#include <stdio.h>
#include <string.h>
#include <algorithm>

#define clr(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<int mod>
struct ModInt {
    const static int MD = mod;
    int x;
    ModInt(ll x = 0): x(x % MD) {}
    int get() { return x; }

    ModInt operator + (const ModInt &that) const { int x0 = x + that.x; return ModInt(x0 < MD? x0 : x0 - MD); }
    ModInt operator - (const ModInt &that) const { int x0 = x - that.x; return ModInt(x0 < 0? x0 + MD : x0); }
    ModInt operator * (const ModInt &that) const { return ModInt((long long)x * that.x % MD); }
    ModInt operator / (const ModInt &that) const { return *this * that.inverse(); }

    ModInt operator += (const ModInt &that) { x += that.x; if (x >= MD) x -= MD; return *this;}
    ModInt operator -= (const ModInt &that) { x -= that.x; if (x < 0) x += MD; }
    ModInt operator *= (const ModInt &that) { x = (long long)x * that.x % MD; return *this;}
    ModInt operator /= (const ModInt &that) { *this = *this / that; }

    ModInt inverse() const {
        int a = x, b = MD, u = 1, v = 0;
        while(b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if(u < 0) u += MD;
        return u;
    }

};
typedef ModInt<1000000007> mint;
struct edgenode
{
    int nxt, v;
}edge[605];
int head[305];
int totedge;
void initedge()
{
    totedge = 0;
    clr(head, -1);
}
void addedge(int u, int v)
{
    edge[totedge].v = v;
    edge[totedge].nxt = head[u];
    head[u] = totedge++;
}
int n;
int ed[305];
int bg[305];
mint dp[305][3][300 * 2 + 1];
mint g[3][300 * 2 + 1];
const int d = 300;
const long long MOD = 1000000007;
inline void initg()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 601; j++)
            g[i][j].x = 0;
}
void dfs(int r, int fa)
{
    dp[r][0][d] = 2;
    dp[r][1][d] = 1;
    bg[r] = ed[r] = 0;
    int p = head[r];
    while(~p)
    {
        if(edge[p].v != fa)
        {
            int c = edge[p].v;
            dfs(c, r);

            //meg
            initg();
            for(int x = bg[r]; x <= ed[r]; x++)
                for(int y = bg[c] - 1; y <= ed[c] + 1; y++)
                {
                    if(x + y < -n || x + y > n) continue;
                    g[0][x + y + d] += dp[r][0][x + d] * dp[c][0][y + d]
                                       + dp[r][0][x + d] * dp[c][1][y + d - 1]
                                       + dp[r][0][x + d] * dp[c][2][y + d + 1];
                    g[1][x + y + d] += dp[r][1][x + d] * dp[c][0][y + d]
                                       + dp[r][1][x + d] * dp[c][2][y + d]
                                       + dp[r][2][x + d] * dp[c][1][y + d];
                    g[2][x + y + d] += dp[r][2][x + d] * dp[c][0][y + d]
                                       + dp[r][1][x + d] * dp[c][1][y + d]
                                       + dp[r][2][x + d] * dp[c][2][y + d];
                    if(g[0][x + y + d].x | g[1][x + y + d].x | g[2][x + y + d].x)
                    {
                        if(x + y < bg[r]) bg[r] = x + y;
                        if(x + y > ed[r]) ed[r] = x + y;
                    }
                }
            for(int i = bg[r]; i <= ed[r]; i++)
            {
                dp[r][0][i + d].x = g[0][i + d].x;
                dp[r][1][i + d].x = g[1][i + d].x;
                dp[r][2][i + d].x = g[2][i + d].x;
            }
        }
        p = edge[p].nxt;
    }
}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        int u,v;
        initedge();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        for(int i = 0; i < 305; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 601; k++)
                    dp[i][j][k].x = 0;
        dfs(1,0);
        mint ans(0);
        for(int i = bg[1]; i <= ed[1]; i++)
        {
            ans = ans + dp[1][0][i + d] * mint(std::max(i,0));
            ans = ans + dp[1][1][i + d] * mint(std::max(i + 1, 0));
            ans = ans + dp[1][2][i + d] * mint(std::max(i - 1, 0));
        }
        ans = ans * mint(3);
        printf("%d\n", ans.x);
    }
}
