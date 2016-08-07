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

LL gcd(LL a, LL b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
inline LL readLL()
{
    char ch;bool flag = false;LL a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
inline int read()
{
    char ch;bool flag = false;int a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
int a[16][16];
const int HASH = 10007;
const int STATE = 1 << 16;
struct HASHMAP
{
    int head[HASH],next[STATE],size;
    int state[STATE];
    int f[STATE];
    void init()
    {
        size = 0;
        clr(head, -1);
    }
    void push(int st, int ans)
    {
        int i,h = st % HASH;
        for(i = head[h]; ~i; i = next[i])
            if(state[i] == st)
            {
                f[i] = max(f[i],ans);
                return;
            }
        state[size] = st;
        f[size] = ans;
        next[size] = head[h];
        head[h] = size++;
    }
}hm[2];
int main()
{
    int _T = read();
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        int n = read();
        FOR(i,n) FOR(j,n) a[i][j] = read();
        int cur = 0;
        hm[cur].init(); hm[cur].push(0,0);
        FOR(i,n)
        {
            hm[cur ^ 1].init();
            FOR(it,hm[cur].size)
                FOR(j,n) if(!(hm[cur].state[it] >> j & 1))
                    hm[cur ^ 1].push(hm[cur].state[it] ^ (1 << j), hm[cur].f[it] + a[i][j]);
            cur ^= 1;
        }
        int ans = 0;
        FOR(it, hm[cur].size)
            ans = max(ans, hm[cur].f[it]);
        printf("Case %d: %d\n",CAS,ans);
    }
    return 0;
}
