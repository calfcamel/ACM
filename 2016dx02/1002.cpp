#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;

//#pragma comment(linker, "/STACK:102400000,102400000")

#define MP3(x,y,z) make_pair(make_pair(x,y),z)
#define MP make_pair
#define AA first
#define XX first.first
#define YY first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl

const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = (1 << 16) + 5;
struct edge
{
    int ch,nxt;
}e[MAXN];
int tot = 0;
int h[MAXN];
void initch(int n)
{
    tot = 0;
    FORR(i,n) h[i] = -1;
}
void addch(int c, int f)
{
    e[tot].ch = c;
    e[tot].nxt = h[f];
    h[f] = tot++;
}
int father[MAXN];
int w[MAXN];
LL sum;
LL f[MAXN];
LL ff[1 << 8][1 << 8];
LL tmp[MAXN][1 << 8];
const int getl8 = (1 << 8) - 1;
int n;
char str[10];
int op(int a, int b)
{
    if(str[0] == 'A') return a & b;
    if(str[0] == 'X') return a ^ b;
    return a | b;
}
void dfs(int k)
{
    int x = w[k] >> 8;
    int y = w[k] & getl8;
    f[k] = w[k];
    FOR(a, 1 << 8) if(~ff[a][y]) f[k] = max(f[k], (LL)w[k] + (op(a,x) << 8) + ff[a][y]);
    sum += f[k] % MOD * k % MOD;
    //printf("f %d = %lld\n", k, f[k]);
    sum %= MOD;
    FOR(b, 1 << 8) tmp[k][b] = ff[x][b];
    FOR(b, 1 << 8) ff[x][b] = max(ff[x][b], f[k] + op(b,y) - w[k]);
    int i = h[k];
    while(~i)
    {
        dfs(e[i].ch);
        i = e[i].nxt;
    }
    FOR(b, 1 << 8) ff[x][b] = tmp[k][b];
}
void initff()
{
    clr(ff,-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&n,str);
        FORR(i,n) scanf("%d",&w[i]);
        REP(i,2,n) scanf("%d",&father[i]);
        initch(n);
        REP(i,2,n) addch(i, father[i]);
        sum = 0;
        initff();
        dfs(1);
        printf("%lld\n", sum);
    }
    return 0;
}
