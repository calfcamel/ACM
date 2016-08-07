
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
const int HASH = 105;
const int STATE = 1002;
inline void upd(int &x, int y)
{
    x += y;
    if(x > MOD) x-= MOD;
}
int n,s;
struct HASHMAP
{
    int size;
    int f[STATE];
    int st[STATE];
    int h[HASH];
    int nxt[STATE];
    void init()
    {
        clr(h, -1);
        size = 0;
    }
    void push(int mask, int y)
    {
        //printf("PUSH %d %d\n",mask, y);
        if(mask > s) return;
        int H = mask % HASH;
        int i = h[H];
        while(~i)
        {
            if(st[i] == mask)
            {
                upd(f[i],y);
                return;
            }
            i = nxt[i];
        }
        st[size] = mask;
        f[size] = y;
        nxt[size] = h[H];
        h[H] = size++;
    }
}hm[1001][2];
int a[1001];
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d%d",&n,&s);
        FOR(i,n) scanf("%d", &a[i]);
        int cur = 0;
        REP(i,0,s) hm[i][cur].init();
        hm[0][cur].push(0,1);
        FOR(i,n)
        {

            //FORR(j,s) hm[j][cur ^ 1].init();
            for(int j = i; j >= 0; j--)
            {
                FOR(it, hm[j][cur].size)
                {
                    hm[j + 1][cur].push(hm[j][cur].st[it] + a[i], hm[j][cur].f[it]);
                    //printf("NOW %d %d %d %d %d\n", i,j,it, hm[j][cur].st[it], hm[j][cur].f[it]);
                }
            }
        }
        int ans = 0;
        REP(j,2,n + 1 - 2)
        {
            LL tp = (LL)j * (j - 1) * (n - j) * (n - j - 1) % MOD;
            FOR(it, hm[j][cur].size)
                upd(ans, (LL)hm[j][cur].f[it] * tp % MOD);
        }
        printf("%d\n",ans);
    }
    return 0;
}
