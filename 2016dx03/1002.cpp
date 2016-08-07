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
int n;
int a[1005];
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        FORR(i,n) scanf("%d",&a[i]);
        double sum0 = 0;
        double sum1 = 0;
        FORR(i,n)
        {
            if(i == 1 || i == n) sum0 += a[i];
            else sum1 += a[i];
        }
        double gx0 = 0;
        double gx1 = 0;
        double ans;
        if(n == 1) ans = a[1];
        else if(n == 2) ans = (a[1] + a[2]) / 2.0;
        else
        {
            REP(i,2,n) gx0 += i - 1;
            gx0 /= n;
            gx0 /= n - 1;
            REP(i,3,n) gx1 += (i - 1) * (i - 2);
            gx1 /= n;
            gx1 /= n - 1;
            gx1 /= n - 2;
            ans = gx0 * sum0 + gx1 * sum1;
        }
        printf("%.10f\n",ans);
    }
}
