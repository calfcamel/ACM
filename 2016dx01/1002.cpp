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

const int MAXN = 100000 + 5;

int sg[1 << 20];
int f[1 << 20];
vector<int> v[2];
inline int mex(int st)
{
    int i = 0;
    while(1)
    {
        if((f[st] & 1) == 0) return i;
        i++;
        f[st] >>= 1;
    }
    return 0;
}
int dfs(int st)
{
    if(~sg[st]) return sg[st];
    int black = -1;
    FOR(i,20)
    {
        if(st & (1 << i))
        {
            if(~black) f[st] |= 1 << dfs((st | (1 << black)) & (~(1 << i)));
        }
        else black = i;
    }
    //FOR(i,v[st].size())
    //    f[st] |= 1 << dfs(v[st][i]);
    return sg[st] = mex(st);
}
int gn[20];
void getnext(int st)
{
    FOR(i,20)
        gn[i] = st & (1 << i);
    int black = -1;
    FOR(i,20)
    {
        if(gn[i])
        {
            if(~black)
                v[st].PB((st | (1 << black)) & (~(1 << i)));
        }
        else black = i;
    }
}
void init()
{
    clr(f,0);
    clr(sg,-1);
    for(int i = 1; i <= 20; i++)
        sg[(1 << i) - 1] = 0;
    sg[0] = 0;
    //FOR(i, 1 << 20) if(!~sg[i])
    //    getnext(i);
    FOR(i, 1 << 20)
        if(!~sg[i])
            dfs(i);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans = 0;
        int n;
        scanf("%d",&n);
        int m;
        int x;
        int st;
        FOR(i,n)
        {
            st = 0;
            scanf("%d",&m);
            FOR(i,m)
            {
                scanf("%d",&x);
                st |= 1 << (20 - x);
            }
            ans ^= sg[st];
        }
        if(ans)
            puts("YES");
        else
            puts("NO");
    }
}
