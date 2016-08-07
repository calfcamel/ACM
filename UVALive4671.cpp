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
//using namespace std;
using std::swap;
using std::pair;
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
struct complex
{
    double r,i;
    complex(double r = 0,double i = 0):r(r),i(i){};
    complex operator + (const complex &b){return complex(r + b.r, i + b.i);}
    complex operator - (const complex &b){return complex(r - b.r, i - b.i);}
    complex operator * (const complex &b){return complex(r * b.r - i * b.i, r * b.i + i * b.r);}
};
void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len / 2; i < len - 1; i++)
    {
        if(i < j) swap(y[i], y[j]);
        k = len >> 1;
        while( j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k)j += k;
    }
}
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
const int MAX_FFT = 1 << 18;
complex x1[MAX_FFT];
complex x2[MAX_FFT];
int ret_fft[2][MAX_FFT];
int sum[MAX_FFT];
char S[1 << 17];
char T[1 << 17];
int lS,lT;
void FFT(int now, int len)
{
    char ch = 'a' + now;
    FOR(i,len) x1[i].r = x1[i].i = x2[i].r = x2[i].i = 0;
    FOR(i,lS) if(ch == S[i]) x1[i + 1].r = 1;
    FOR(i,lT) if(ch == T[i]) x2[lT - i].r = 1;
    fft(x1,len,1);
    fft(x2,len,1);
    FOR(i,len) x1[i] = x1[i] * x2[i];
    fft(x1,len,-1);
    FOR(i,len) ret_fft[now][i] = (int)(x1[i].r + 0.5);
}
unsigned long long a[1 << 17];
int main()
{
    int k;
    int cas = 1;
    while(~scanf("%d",&k) && ~k)
    {
        scanf("%s%s",S,T);
        lS = strlen(S);
        lT = strlen(T);
        int len = 1;
        while(len < lS || len < lT) len <<= 1; len <<= 1;
        FOR(i,2)
            FFT(i,len);
        FOR(i,len)
        {
            sum[i] = 0;
            FOR(j,2)
                sum[i] += ret_fft[j][i];
        }
        a[0] = 0;
        REP(i,1,lS)
            a[i] = a[i - 1] * 3 + S[i - 1] - 'a';
        std::map<unsigned long long, int> mp;
        unsigned long long mul = 1;
        FOR(i,lT) mul *= 3;
        int ans = 0;
        REP(i, lT + 1, lS + 1)
        {
            if(sum[i] + k >= lT)
            {
                if(mp[a[i - 1] - a[i - 1 - lT] * mul] == 0)
                {
                    ans++;
                    mp[a[i - 1] - a[i - 1 - lT] * mul] = 1;
                }
            }
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
