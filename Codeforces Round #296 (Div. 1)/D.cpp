#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const double PI = acos(-1.0);
const int MAX_FFT = 1 << 19;
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

vector<int> vA,vC,vG,vT;
complex x1[MAX_FFT];
complex x2[MAX_FFT];

const int MAXN = 200000 + 5;
int sum[MAXN];
int lS,lT;
int k;
char S[MAXN];
char T[MAXN];

vector<int> FFT(char ch, int len)
{
    for(int i = 0; i < len; i++) x1[i] = x2[i] = complex(0,0);
    sum[0] = 0;
    for(int i = 1; i <= lS; i++)
    {
        sum[i] = sum[i - 1];
        if(S[i - 1] == ch) sum[i]++;
    }
    int l,r;
    for(int i = 1; i <= lS; i++)
    {
        l = max(1, i - k);
        r = min(lS, i + k);
        if(sum[r] - sum[l - 1] > 0)
            x1[i].r = 1.0;
    }
    for(int i = 1; i <= lT; i++)
        if(T[i - 1] == ch)
            x2[lT + 1 - i].r = 1.0;
    fft(x1, len, 1);
    fft(x2, len, 1);
    for(int i = 0; i < len; i++)
        x1[i] = x1[i] * x2[i];
    fft(x1, len, -1);
    vector<int> ret;
    ret.clear();
    for(int i = 0; i < len; i++)
        ret.push_back((int)(x1[i].r + 0.5));
    return ret;
}

int main()
{
    scanf("%d%d%d",&lS, &lT, &k);
    scanf("%s%s", S, T);
    int len = 1;
    for(len = 1; len <= lS || len <= lT; len <<= 1); len <<= 1;
    vA = FFT('A', len);
    vC = FFT('C', len);
    vG = FFT('G', len);
    vT = FFT('T', len);
    int ans = 0;
    for(int i = 1; i < len; i++)
        if(vA[i] + vC[i] + vG[i] + vT[i] == lT) ans++;
    printf("%d\n",ans);
    return 0;
}
