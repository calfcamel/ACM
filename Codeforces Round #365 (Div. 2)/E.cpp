#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<pii,LL> piil;
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
const int N = 1000000;
LL prime[N];
bool check[N];
int totp;
void Eular()
{
	clr(check,false);
    totp = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[totp++] = i;
		for (int j = 0; j < totp; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int totfj;
LL fj[20];
int numfj[20];
void fenjie(LL n)
{
    totfj = 0;
    FOR(i, totp)
    {
        if(n < prime[i]) break;
        if(n % prime[i] == 0)
        {
            numfj[totfj] = 0;
            fj[totfj] = prime[i];
            while(n % prime[i] == 0) n /= prime[i], numfj[totfj]++;
            totfj++;
        }
    }
    if(n > 1)
    {
        fj[totfj++] = n;
    }
}
int totys;
LL ys[10010];
void getys(LL n)
{
    fenjie(n);
    totys = 0;
    ys[totys++] = 1;
    int tmp;
    LL mul;
    FOR(i,totfj)
    {
        tmp = totys;
        mul = 1;
        FOR(j,numfj[i])
        {
            mul *= fj[i]; FOR(k,tmp) ys[totys++] = mul * ys[k];
        }
    }
}
LL a[1010];
LL b[1010];
int dp[1010][10010];
piil path[1010][10010];
unordered_map<LL,int> zip;
unordered_map<int,LL> unzip;
const int inf = 100000;
const LL infLL = 9000000000000000000LL;
int main()
{
    //cout << infLL << endl;
    Eular();
    int n; n = read();
    LL k; k = readLL();
    FORR(i,n) a[i] = readLL();//cout << "END_READ" << endl;
    FORR(i,n) b[i] = gcd(k,a[i]); //cout << "END" << endl;
    if(k == 1)
    {
        int ans = 1;
        FORR(i,n)
            if(a[ans] > a[i]) ans = i;
        cout << "1" << endl;
        cout << ans << endl;
        return 0;
    }
    getys(k);
    if(totys >= 10010) return -1;
    FOR(i,totys) zip[ys[i]] = i, unzip[i] = ys[i];
    /*
    cout << "totp = " << totp << endl;
    cout << "prime:";FOR(i,30) cout << prime[i] << " "; cout << endl;
    cout << "fj:";FOR(i,totfj) cout << fj[i] << "^" << numfj[i] << " ";cout << endl;
    cout << "ys:";FOR(i,totys) cout << ys[i] << " ";cout << endl;
    */
    FOR(i,n + 1) FOR(j,totys) dp[i][j] = inf;
    path[n][totys - 1] = MP3(inf,inf, infLL);
    path[0][0] = MP3(inf, inf, 0LL);
    LL now;
    LL nxt;
    int inow;
    int inxt;
    dp[0][0] = 0;
    //cout << "START_DP" << endl;
    FOR(i,n)
    {
        //cout << "NOW_DP_" << i << " a[i] = " << a[i + 1] << " b[i] = " << b[i + 1] << endl;
        FOR(j, totys) if(dp[i][j] != inf) if(dp[i + 1][j] == dp[i][j])
            {if(path[i + 1][j].BB > path[i][j].BB) path[i + 1][j] = path[i][j];}
        FOR(j, totys) if(dp[i + 1][j] > dp[i][j])
            {dp[i + 1][j] = dp[i][j]; path[i + 1][j] = path[i][j];}
        //cout << "\t STEP 2" << endl;
        FOR(j, totys) if(dp[i][j] != inf)
        {
            now = unzip[j];
            nxt = gcd(k / b[i + 1], now) * b[i + 1];
            inxt = zip[nxt];
            //cout << "\t\tj = " << j << " now = " << now << " nxt = " << nxt <<" inxt = " << inxt << endl;
            if(dp[i + 1][inxt] == dp[i][j] + 1)
                {if(path[i + 1][inxt].BB > path[i][j].BB + a[i + 1]) path[i + 1][inxt] = MP3(i,j, path[i][j].BB + a[i + 1]);}
            if(dp[i + 1][inxt] > dp[i][j] + 1)
                {dp[i + 1][inxt] = dp[i][j] + 1; path[i + 1][inxt] = MP3(i,j, path[i][j].BB + a[i + 1]);}
        }
        //FOR(j,totys) if(dp[i][j] != inf)
        //    cout << "\t" << i << " " << j << "(" << unzip[j] << ") = " << dp[i][j] << " path = " << path[i][j].AA.AA << " " << path[i][j].AA.BB << " " << path[i][j].BB << endl;
    }
    //cout << "END_DP" << endl;
    if(dp[n][totys - 1] == inf) {puts("-1"); return 0;}
    printf("%d\n", dp[n][totys - 1]);
    pii pit(n, totys - 1);
    int flag = 1;
    while(pit.AA != inf && pit.BB != inf)
    {
        pit = path[pit.AA][pit.BB].AA;
        if(pit.AA == inf) break;
        if(flag) flag = 0; else printf(" ");
        printf("%d",pit.AA + 1);
    }
    puts("");
    return 0;
}
