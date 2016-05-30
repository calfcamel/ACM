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
int n,l,m;
int a[10004];
int sum[10004];
int dp[2][10004];
multiset<int> S;
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d%d%d",&n,&m,&l);
        FORR(i,n)
            scanf("%d",&a[i]);
        sum[0] = 0;
        FORR(i,n)
            sum[i] = sum[i - 1] ^ a[i];
        int cur = 0;
        clr(dp,-1);
        dp[cur][0] = 0;
        FOR(l,m)
        {
            S.clear();
            REP(i,0,n)
            {
                if(i - l >= 0 && ~dp[cur][i - l])
                    del();
                if(!S.empty())
                {
                    dp[cur ^ 1][i] = getdp();
                }
                else dp[cur ^ 1][i] = 0;
                if(~dp[cur][i])
                    add();
            }
        }
        printf("Case #%d:\n%d\n",CAS,ans);
    }
    return 0;
}
