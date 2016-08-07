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

    const int MAX = 100005;
const int MAXN = 100000 + 5;
struct BIT
{
    int a[MAX];
    void init()
    {
        clr(a,0);
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x)
    {
        for(int i = x; i < MAX; i += lowbit(i))
        {
            a[i] ++;
        }
    }
    int get(int x)
    {
        int ret = 0;
        for(int i = x; i > 0; i -= lowbit(i))
        {
            ret += a[i];
        }
        return ret;
    }
}bit;
pair<int, int> a[100005];
int main()
{
    int T;
    scanf("%d",&T);
    FORR(cas, T)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d:", cas);
        FOR(i,n)
        {
            scanf("%d", &a[i].AA);
            a[i].BB = i + 1;
        }
        sort(a, a + n);
        bit.init();
        int x,y,z;
        int mi,ma;
        int ans;
        FOR(i,n)
        {
            x = a[i].BB;
            z = a[i].AA;
            y = i - bit.get(x);
            y += x;
            bit.add(x);
            mi = min(x,y);
            mi = min(mi,z);
            ma = max(y,x);
            ma = max(ma,z);
            ans = ma - mi;
            //printf("[%d %d %d]",x,y,z);
            if(ans < 0) ans =-ans;
            printf(" %d", ans);
        }
        puts("");
    }
    return 0;
}
