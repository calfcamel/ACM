#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
//#define double long double
const long double PI = acos(-1.0);

typedef long long LL;
#define clr(a,b) memset(a,b,sizeof(a))
const int N = 50001;
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
bool vis[N];
char str[10];
struct complex
{
    long double r,i;
    complex(long double r = 0,long double i = 0):r(r),i(i){};
    complex operator + (const complex &b){return complex(r + b.r, i + b.i);}
    complex operator - (const complex &b){return complex(r - b.r, i - b.i);}
    complex operator * (const complex &b){return complex(r * b.r - i * b.i, r * b.i + i * b.r);}
};
void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len / 2; i < len - 1; i++)
    {
        if(i < j) std::swap(y[i], y[j]);
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
void init()
{
    Eular();
    memset(vis,0,sizeof vis);
    for(int i = 0; i < totp; i++)
        vis[prime[i]] = 1;
    vis[0] = 1;
    vis[1] = 1;
}
complex H[1 << 19];
complex S[1 << 19];
complex C[1 << 19];
complex D[1 << 19];
int a,b,c;
int main()
{
    init();
    while(scanf("%d%d%d",&a,&b,&c) == 3)
    {
        if(a + b + c == 0) return 0;
        int l = 1;
        while(l < b) l <<= 1;
        l <<= 3;
        int x;
        for(int i = 0; i <= b; i++)
        {
            x = vis[i]? 0:1;
            H[i] = S[i] = C[i] = D[i] = complex(x,0);
        }
        for(int i = b + 1; i < l; i++)
            H[i] = S[i] = C[i] = D[i] = complex(0,0);
        char ch;
        int t;
        for(int i = 0; i < c; i++)
        {
            scanf("%d%c",&x,&ch);
            if(ch == 'H') H[x] = complex(0,0);
            if(ch == 'S') S[x] = complex(0,0);
            if(ch == 'C') C[x] = complex(0,0);
            if(ch == 'D') D[x] = complex(0,0);
        }
        fft(H, l, 1);
        fft(S, l, 1);
        fft(C, l, 1);
        fft(D, l, 1);
        for(int i = 0; i < l; i++)
            H[i] = H[i] * S[i] * C[i] * D[i];
        fft(H, l, -1);
        for(int i = a; i <= b; i++)
            printf("%lld\n", (long long)(H[i].r + 0.5));
        puts("");
    }
}
