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
int popc[1024];
int a[70];
const int HASH = 500007;
const int STATE = 1000006;
struct HASHMAP
{
    int h[HASH];
    int st[STATE];
    int nxt[STATE];
    LL f[STATE];
    int size;
    void init()
    {
        clr(h, -1);
        size = 0;
    }
    void push(int mask, LL ans)
    {
        //cout << "PUSH ";
        //cout << (mask & 1) << " ";
        //int t = mask >> 1;
        //while(t) {cout << (t & 15); t >>= 4;}
        //cout << " " << ans << endl;
        int head = mask % HASH;
        int i = h[head];
        while(~i)
        {
            if(st[i] == mask)
            {
                f[i] += ans;
                return;
            }
            i = nxt[i];
        }
        f[size] = ans;
        st[size] = mask;
        nxt[size] = h[head];
        h[head] = size++;
    }
}hm[2];
std::map<pair<LL,int>,LL> mp;
LL get(LL n, int k)
{
    if(mp[make_pair(n,k)]) return mp[make_pair(n,k)];
    LL ret = 0;
    if(n == 0) return 0;
    LL nn = n;
    int m = 0;
    while(nn)
    {
        a[m++] = nn % 10;
        nn /= 10;
    }
    int cur = 0;
    int flag;
    LL d;
    int mask;
    int cnt;
    hm[cur].init();
    FORR(i,a[m - 1])
    {
        if(i == a[m - 1]) hm[cur].push((i << 1) | 1, 1);
        else hm[cur].push((i << 1), 1);
    }
    int now;
    int chk;
    int chkflag;
    int nowand = 1 << ((k - 1) << 2);
    nowand --;
    for(int i = m - 2; i >= 0; i--)
    {
        hm[cur ^ 1].init();
        FOR(it, hm[cur].size)
        {
            mask = hm[cur].st[it];
            d = hm[cur].f[it];
            flag = mask & 1;
            mask >>= 1;
            cnt = m - 1 - i;
            cnt = min(cnt, k - 1);
            FOR(k,10)
            {
                if(flag && k > a[i]) break;
                if(flag && k == a[i])
                {
                    chk = mask;
                    chkflag = 1;
                    FOR(p, cnt)
                    {
                        if((chk & 15) == k) chkflag = 0;
                        chk >>= 4;
                    }
                    if(!chkflag) continue;
                    now = mask << 4;
                    now &= nowand;
                    now |= k;
                    hm[cur ^ 1].push((now << 1) | 1, d);
                    break;
                }
                    chk = mask;
                    chkflag = 1;
                    FOR(p, cnt)
                    {
                        if((chk & 15) == k) chkflag = 0;
                        chk >>= 4;
                    }
                    if(!chkflag) continue;
                    now = mask << 4;
                    now &= nowand;
                    now |= k;
                    hm[cur ^ 1].push(now << 1, d);
            }
        }
        cur ^= 1;
    }
    FOR(it, hm[cur].size)
        ret += hm[cur].f[it];
    LL x = 10;
    while(1)
    {
        if(x > n) break;
        //if(x <= n) ret += get(x - 1, k);
        x *= 10;
    }
    x /= 10;
    if(n == 1000000000000000000l) x = (LL) 1000000000 * (LL) 1000000000;
    //cout << "x = " << x << endl;
    if(x > 8) ret += get(x - 1, k);
    //cout << "GET " << n << " " << k << " = " << ret << endl;
    return ret;
}
void run(LL L, LL R, int k)
{
    cout << get(R,k) - get(L - 1,k) << endl;
}
void init()
{
    FOR(i, 1 << 10) popc[i] = __builtin_popcount(i);
}
int main()
{
    init();
    LL L,R;
    int k;
    while(cin >> L >> R >> k)
    {
        //cout << R * 10 << endl;
        run(L, R, k);
    }
    return 0;
}
