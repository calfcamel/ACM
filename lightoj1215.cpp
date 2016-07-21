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

const int N = 1000006;
long long prime[N];
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
long long a,b,c,L;
long long fj[200];
void getC()
{
    if(L % a) return;
    if(L % b) return;
    long long n = L;
    int tot = 0;
    for(int i = 0; i < totp; i++) if(n % prime[i] == 0)
    {
        fj[tot] = 1;
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            fj[tot] *= prime[i];
        }
        tot++;
    }
    if(n > 1)
        fj[tot++] = n;
    for(int i = 0; i < tot; i++)
    {
        if(a % fj[i] == 0 || b % fj[i] == 0)
            fj[i] = 1;
    }
    c = 1;
    for(int i = 0; i < tot; i++)
        c *= fj[i];
}
int main()
{
    Eular();
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%lld%lld%lld",&a,&b,&L);
        c = -1;
        getC();
        printf("Case %d: ",CAS);
        if(c == -1)
            puts("impossible");
        else printf("%lld\n", c);
    }
    return 0;
}
