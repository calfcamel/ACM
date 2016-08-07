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
int a[MAXN];
int b[MAXN];
int f[MAXN];
map<int,int> mp;
int main()
{
    int n;
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,n) b[i] = a[i];
    sort(b,b + n);
    int m = unique(b, b + n) - b;
    int tot = 0;
    FOR(i,m) mp[b[i]] = tot++;
    FOR(i,n) a[i] = mp[a[i]];
    int r = 0;
    FOR(i,n)
    {
        if(r == 0)
        {
            f[r++] = a[i];
            continue;
        }
        if(f[r - 1] < a[i])
        {
            f[r++] = a[i];
        }
        else
        {
            int x = upper_bound(f, f + r, a[i]) - f;
            if(f[x] != a[i]) f[x] = a[i];
        }
    }
    printf("%d\n",r);
    return 0;
}
