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

const int MAXN = 1000000 + 6;

int n;
int a[1000006];
int b[1000006];
int ans[1000006];
int m;
map<int,int> mp;
vector<piii> v;
inline int lb(int i) {return i & -i;}
struct BIT
{
    int a[MAXN];
    void init()
    {
        clr(a,0);
    }
    void upd(int x, int y)
    {
        for(int i = x; i < MAXN; i += lb(i)) a[i] ^= y;
    }
    int qry(int x)
    {
        int ret = 0;
        for(int i = x; i > 0; i -= lb(i)) ret ^= a[i];
        return ret;
    }
}bit;
int main()
{
    scanf("%d",&n);
    FORR(i,n) scanf("%d",&a[i]);
    b[0] = 0;
    int x,y;
    a[0] = 0;
    FORR(i,n)
        b[i] = b[i - 1] ^ a[i];

    scanf("%d",&m);
    FOR(i,m)
    {
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(make_pair(y,x),i));
    }
    sort(v.begin(), v.end());
    int it = 0;
    int sz = v.size();
    int t;
    int now;
    FORR(i,n)
    {
        t = mp[a[i]];
        mp[a[i]] = i;
        if(t) bit.upd(t,a[i]);
        now = bit.qry(i);
        while(it < sz && v[it].AA.AA == i)
        {
            ans[v[it].BB] = now ^ bit.qry(v[it].AA.BB - 1);
            it++;
        }
    }
    FOR(i,m)
        printf("%d\n",ans[i]);
    return 0;
}
