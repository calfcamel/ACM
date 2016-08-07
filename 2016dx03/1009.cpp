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

const int MAXN = 100000 + 5;
int a[5005];
int aa[20005];
int n;
int pre[5005][5005];
int nxt[5005][5005];
int dp[5005][5005];
long long sum[5005][5005];
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        FORR(i,n)
            scanf("%d",&a[i]);
        clr(aa, 0);
        int m = 0;
        FORR(i,n)
            if(aa[a[i]] == 0) aa[a[i]]++;
        REP(i,0,20000)
            if(aa[i]) aa[i] = ++m;
        FORR(i,n) a[i] = aa[a[i]];
        //FORR(i,n) printf("a[i] = %d\n",a[i]);
        clr(pre, 0);
        REP(i,2,n + 1)
            REP(j,1,i - 1)
                pre[i][a[j]] = j;
        clr(nxt,0);
        REP(i,0,n - 1)
            REP_D(j,n, i + 1)
                nxt[i][a[j]] = j;
        clr(dp, 0);
        clr(sum, 0);
        FORR(i,n)
        {
            dp[i][i] = 1;
            sum[i][i] = 1;
        }
        REP_D(i,n - 1, 1)
        {
            int ansdp = 0;
            long long anssum = 1;
            REP(j, i + 1, n)
            {
                //printf("\ti = %d j = %d a[j] = %d a[i] = %d\n",i,j,a[j],a[i]);
                if(a[j - 1] <= a[i])
                {
                    //printf("\thello\n");
                    if(dp[nxt[i][a[j - 1]]][pre[j - 1][a[j - 1]]] == ansdp)
                        anssum -= sum[nxt[i][a[j - 1]]][pre[j - 1][a[j - 1]]];
                    if(anssum < 0) anssum += MOD;
                    int f = dp[nxt[i][a[j - 1]]][j - 1];
                    //printf("\t f = %d nxt = %d j-1 = %d\n", f, nxt[i][a[j - 1]], j - 1);
                    long long s = sum[nxt[i][a[j - 1]]][j - 1];
                    if(f > ansdp)
                    {
                        ansdp = f;
                        anssum = s;
                    }
                    else if(f == ansdp)
                    {
                        anssum += s;
                        if(anssum > MOD) anssum -= MOD;
                    }
                }
                if(a[j] == a[i])
                {
                    dp[i][j] = ansdp + 2;
                    sum[i][j] = anssum;
                }
                else dp[i][j] = 0;
                //printf("dp[%d][%d] = %d %lld\n", i, j, dp[i][j], sum[i][j]);
            }
        }
        int ansdp = 1;
        long long anssum = 0;
        REP(i,1,m)
        {
            int f = dp[nxt[0][i]][pre[n + 1][i]];
            long long s = sum[nxt[0][i]][pre[n + 1][i]];
            if(f > ansdp)
            {
                ansdp = f;
                anssum = s;
            }
            else if(f == ansdp)
            {
                anssum += s;
                if(anssum > MOD) anssum -= MOD;
            }
        }
        printf("%d %lld\n", ansdp, anssum);
    }
    return 0;
}
