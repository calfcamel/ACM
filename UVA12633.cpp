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

using std::swap;
using std::min;
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

const int MAXN = 50000 + 5;
int R[MAXN];
int C[MAXN];
int D[MAXN * 2];
int sR[MAXN];
int sC[MAXN];
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
long long run()
{
    int r,c;
    int n;
    scanf("%d%d",&r,&c);
    scanf("%d",&n);
    int lR = 0;
    int lC = 0;
    int lD = 0;
    int _x,_y;
    clr(R, 0);
    clr(C, 0);
    clr(D, 0);
    FOR(i,n)
    {
        scanf("%d%d",&_x,&_y);
        R[_x] = 1;
        C[_y] = 1;
        D[_x - _y + c] = 1;
    }
    FORR(i,r) if(R[i]) lR++;
    FORR(j,c) if(C[j]) lC++;
    REP(k, 1, r - 1 + c) if(D[k]) lD++;
    LL _absD = 0;
    int _d;
    REP(k, 1, r - 1 + c) if(D[k]) {_d = k - c; if(_d > 0) _absD += min(min(r,c),r - _d); else _absD += min(min(r,c), c + _d);}
    LL ans = (LL)lR * c + (LL)lC * r + _absD;
    //printf("R = %lld C = %lld D = %lld\n", (LL)lR * c , (LL)lC * r, _absD);
    ans -= (LL)lR * lC;
    //printf("ans -= %lld\n",(LL)lR * lC);
    //printf("ans = %lld\n",ans);
    sR[0] = 0; FORR(i, r) sR[i] = sR[i - 1] + R[i];
    sC[0] = 0; FORR(j, c) sC[j] = sC[j - 1] + C[j];
    REP(k,1,r - 1 + c) if(D[k])
    {
        _d = k - c;
        if(_d > 0)
        {
            ans -= sR[r] - sR[_d];
            ans -= sC[c - _d];
        }
        else
        {
            _d = -_d;
            ans -= sR[r - _d];
            ans -= sC[c] - sC[_d];
        }
    }
    //printf("bef fft ans = %lld\n",ans);
    int len = 1;
    while(len < (r + 1) || len < (c + 1)) len <<= 1; len <<= 1;
    FOR(i,len) x1[i].r = x1[i].i = x2[i].r = x2[i].i = 0;
    FORR(i,r) x1[i].r = R[i];
    FORR(i,c) x2[i].r = C[c - i + 1];
    fft(x1,len,1);
    fft(x2,len,1);
    FOR(i,len) x1[i] = x1[i] * x2[i];
    fft(x1,len,-1);
    //printf("fft : ");
    //FOR(i,len) printf("%d ", (int)(x1[i].r + 0.5));
    //puts("");
    REP(i, 2, r + c)
    {
        _d = i - c - 1;
        if(D[_d + c]) ans += (int)(x1[i].r + 0.5);
    }
    //printf("end fft ans = %lld\n",ans);
    return (LL)r * c - ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    FORR(CAS, T)
    {
        //printf("Case %d: %lld\n", CAS, run());
        LL ans = run();
        std::cout << "Case " << CAS << ": " << ans << std::endl;
    }
    return 0;
}
