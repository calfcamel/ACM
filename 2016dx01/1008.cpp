#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
const double PI = acos(-1.0);

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
/*
//调用
    fft(x1,l,1);
    fft(x2,l,1);
    for(i = 0; i < l; i++)
        x1[i] = x1[i] * x2[i];
    fft(x1,l,-1);
// x1[] is ans
LL l = 1;
while(l < MAXN) l <<= 1;
*/
complex x1[300000];
complex x2[300000];
int a[300000];
int f[300000];
int n;
void solve(int l, int r, int length)
{
    if(l == r) return;
    solve(l, l + length / 2 - 1, length >> 1);
    for(int i = 0; i < length * 2; i++)
        x1[i] = complex(0,0);
    for(int i = 0; i < length * 2; i++)
        x2[i] = complex(0,0);
    for(int i = 1; i <= length / 2; i++)
        x1[i] = complex(f[l + i - 1],0);
    for(int i = 1; i <= length; i++)
        x2[i] = complex(a[i], 0);
    fft(x1,length * 2,1);
    fft(x2,length * 2,1);
    for(int i = 0 ; i < length * 2; i++)
        x1[i] = x1[i] * x2[i];
    fft(x1,length * 2,-1);
    for(int i = 1; i <= length / 2; i++)
        f[l + length / 2 + i - 1] = (f[l + length / 2 + i - 1] + (int)(x1[i + length / 2].r + 0.5)) % 313;
    solve(l + length / 2, r, length >> 1);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int l = 1;
        while(l <= n) l <<= 1;
        for(int i = 0; i < l; i++) a[i] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        for(int i = 0; i < l; i++) a[i] %= 313;
        for(int i = 0; i < l; i++) f[i] = a[i];
        for(int i = 0; i < l; i++)
            x2[i] = complex(a[i],0);
        solve(1,l,l);
        printf("%d\n", f[n]);
    }
}
