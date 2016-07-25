
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
const int HASH = 100007;
const int STATE = (1 << 17) * 18 * 3;
struct HASHMAP
{
    int head[HASH],size;
    int state[STATE],f[STATE],nxt[STATE];
    void init()
    {
        size = 0;
        clr(head,-1);
    }
    void push(int st, int ans)
    {
        int h = st % HASH;
        int i = head[h];
        while(~i)
        {
            if(state[i] == st)
            {
                f[i] = std::min(f[i], ans);
                return;
            }
            i = nxt[i];
        }
        state[size] = st;
        f[size] = ans;
        nxt[size] = head[h];
        head[h] = size++;
    }
}hm[2];
inline int getst(int yang, int yin, int j, int k)
{
    int ret = yang;
    ret <<= 9;
    ret |= yin;
    ret <<= 5;
    ret |= j;
    ret <<= 2;
    ret |= k;
    return ret;
}
int n,m;
int a[11][11];
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        clr(a, 0);
        int x,y;
        FOR(i,m)
        {
            scanf("%d%d",&x,&y);
            a[x][y] = 1;
        }
        int cur = 0;
        hm[cur].init();
        int yang = 0;
        int yin = 0;
        int pre = n;
        int k = 2;
        int mk = 3;
        int mp = (1 << 5) - 1;
        int myin = (1 << 9) - 1;
        int myang = (1 << 9) - 1;
        int mask;
        hm[cur].push(getst(yang,yin,pre,k), 0);
        FOR(l,(n << 1))
        {
            //printf("level %d:\n",l);
            hm[cur ^ 1].init();
            FOR(it,hm[cur].size)
            {
                mask = hm[cur].state[it];
                k = mask & mk;
                mask >>= 2;
                pre = mask & mp;
                mask >>= 5;
                yin = mask & myin;
                mask >>= 9;
                yang = mask & myang;

                //printf("\t%d %d %d %d %d\n",yang,yin,pre,k,hm[cur].f[it]);
                if(l == n * 2 - 1) break;
                if(l & 1)
                {
                    pre -= 9;
                    if(k == 2) continue;
                    FOR(i,n - 1) if(!(yin & (1 << i)))
                    {
                        //printf("\t\t k = %d pre = %d i = %d a = %d\n",k,pre,i,a[pre][i]);
                        if(k == 0 && a[pre][i + 1]) continue;
                        //printf("\t\tpush %d %d %d %d %d\n",yang, yin | (1 << i), i + 1, 2, hm[cur].f[it]);
                        hm[cur ^ 1].push(getst(yang, yin | (1 << i), i + 1, 2), hm[cur].f[it]);
                    }
                }
                else
                {
                    // puts yang
                    if(k != 2) continue;
                    FOR(i, n) if(!(yang & (1 << i)))
                    {
                        hm[cur ^ 1].push(getst(yang | (1 << i), yin, i + 10, 1), hm[cur].f[it] + 1);
                        if(!a[i + 1][pre])
                            hm[cur ^ 1].push(getst(yang | (1 << i), yin, i + 10, 0), hm[cur].f[it]);
                    }
                }
            }
            if(l == 2 * n - 1) break;
            cur ^= 1;
        }
        int ans = 9;
        FOR(it, hm[cur].size)
        {
            int mask = hm[cur].state[it];
                k = mask & mk;
                mask >>= 2;
                pre = mask & mp;
                mask >>= 5;
                yin = mask & myin;
                mask >>= 9;
                yang = mask & myang;
            //printf("\t%d %d %d %d %d\n",yang,yin,pre,k,hm[cur].f[it]);
            int tmp = hm[cur].f[it];
            if(k == 0 && a[pre - 9][n]) tmp++;
            ans = min(ans, tmp);
            //ans = std::min(ans, hm[cur].f[it] + (((hm[cur].state[it]) & 3) ? 0:(a[(hm[cur].state[it] >> 2) & mp][n])));
        }
        printf("%d\n",ans);
    }
    return 0;
}
