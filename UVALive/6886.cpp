#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

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
int n,m;
const int MAXN = 200001;
complex x1[262149 * 2];
//complex x2[262149 * 2];
int a[262149];
int l;
int main()
{
    while(scanf("%d",&n) == 1)
    {
        memset(a,0,sizeof a);
        l = 1;
        while(l < MAXN) l <<= 1;
        l <<= 1;
        //l <<= 1;
        //printf("%d\n",l);
        //scanf("%d",&n);
        int x;
        for(int i = 0; i <= l; i++)
        {
            x1[i].r = 0;
            x1[i].i = 0;
            a[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            x1[x].r = 1.0;
            //x2[x].r = 1.0;
            a[x] = 1;
        }
        fft(x1,l,1);
        //fft(x2,l,1);
        for(int i = 0; i < l; i++)
            x1[i] = x1[i] * x1[i];
        fft(x1,l,-1);
        scanf("%d",&m);
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d",&x);
            if(x1[x].r > 0.5 || a[x])
                ans++;
        }
        printf("%d\n", ans);
    }
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