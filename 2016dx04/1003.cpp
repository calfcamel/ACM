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
#define REP_D(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i >= __END__; i--)
#define lowbit(x) (x & -x)

const int N = 20;
int n,m;
int go[1 << N];
int can[1 << N];
int sum[1 << N];
int u[N * N], v[N * N];
int q[1 << N];
int main()
{
    int T;
    scanf("%d",&T);
    FORR(cas, T)
    {
        scanf("%d%d",&n,&m);
        clr(go, 0);
        clr(can, 0);
        clr(sum, 0);
        int x,y;
        FOR(i,m)
        {
            scanf("%d%d",&x,&y);
            u[i] = x;
            v[i] = y;
            go[1 << x] |= 1 << y;
            go[1 << y] |= 1 << x;
        }
        FOR(mask, 1 << n)
        {
            go[mask] |= go[mask ^ lowbit(mask)] | go[lowbit(mask)];
        }
        int l, r;
        l = 0;
        r = 0;
        FOR(i,n) q[r++] = 1 << i;
        FOR(i,n) can[1 << i] = 1;
        while(l < r)
        {
            int now = q[l++];
            int gg = go[now] ^ (go[now] & now);
            for(; gg; gg ^= lowbit(gg))
            {
                int mask = now ^ lowbit(gg);
                if(!can[mask]) can[q[r++] = mask] = 1;
            }
        }
        int all = 0;
        FOR(i, 1 << n)
        {
            int j = i ^ ((1 << n) - 1);
            if(can[i] & can[j]) sum[i]++,all++;
        }
        all >>= 1;
        FOR(d,n) REP_D(mask, (1 << n) - 1, 0) if(!(mask >> d & 1))
            sum[mask] += sum[mask ^ 1 << d];
        printf("Case #%d:",cas);
        FOR(i,m) printf(" %d", all - sum[(1 << v[i]) | (1 << u[i])]);
        puts("");
    }
    return 0;
}
