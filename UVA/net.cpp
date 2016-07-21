/*
 * Author: Gatevin
 * Created Time:  2015/7/15 15:58:33
 * File Name: UVA12298.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;

const long double PI = acos(-1.0);

bool isPrime[50010];
bool check[50010];

void init()
{
    memset(isPrime, 0, sizeof(isPrime));
    memset(check, 0, sizeof(check));
    isPrime[0] = isPrime[1] = 1;
    check[0] = check[1] = 1;
    for(int i = 2; i <= 50000; i++)
    {
        if(check[i]) continue;
        isPrime[i] = 1;
        for(int j = i; j <= 50000; j += i)
            check[j] = 1;
    }
    return;
}

struct Complex
{
    long double real, image;
    Complex(long double _real, long double _image)
    {
        real = _real;
        image = _image;
    }
    Complex(){}
};

Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}

Complex operator - (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}

Complex operator * (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}

int rev(int id, int len)
{
    int ret = 0;
    for(int i = 0; (1 << i) < len; i++)
    {
        ret <<= 1;
        if(id & (1 << i)) ret |= 1;
    }
    return ret;
}

Complex A[1 << 19];
void FFT(Complex *a, int len, int DFT)
{
    for(int i = 0; i < len; i++)
        A[rev(i, len)] = a[i];
    for(int s = 1; (1 << s) <= len; s++)
    {
        int m = (1 << s);
        Complex wm = Complex(cos(DFT*2*PI/m), sin(DFT*2*PI/m));
        for(int k = 0; k < len; k += m)
        {
            Complex w = Complex(1, 0);
            for(int j = 0; j < (m >> 1); j++)
            {
                Complex t = w*A[k + j + (m >> 1)];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + (m >> 1)] = u - t;
                w = w*wm;
            }
        }
    }
    if(DFT == -1) for(int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;
    for(int i = 0; i < len; i++) a[i] = A[i];
    return;
}

Complex S[1 << 19], H[1 << 19], C[1 << 19], D[1 << 19];

int main()
{
    int a, b, c;
    init();
    while(scanf("%d %d %d", &a, &b, &c), a || b || c)
    {
        int len = 1;
        while(len <= b) len <<= 1;
        len <<= 3;
        for(int i = 0; i <= b; i++)
            if(!isPrime[i]) S[i] = H[i] = C[i] = D[i] = Complex(1, 0);
            else S[i] = H[i] = C[i] = D[i] = Complex(0, 0);
        for(int i = b + 1; i < len; i++) S[i] = H[i] = C[i] = D[i] = Complex(0, 0);
        int num;
        char type;
        for(int i = 0; i < c; i++)
        {
            scanf("%d%c", &num, &type);
            switch(type)
            {
                case 'S': S[num] = Complex(0, 0); break;
                case 'H': H[num] = Complex(0, 0); break;
                case 'C': C[num] = Complex(0, 0); break;
                case 'D': D[num] = Complex(0, 0); break;
            }
        }
        FFT(S, len, 1); FFT(H, len, 1); FFT(C, len, 1); FFT(D, len, 1);
        for(int i = 0; i < len; i++)
            S[i] = S[i]*H[i]*C[i]*D[i];
        FFT(S, len, -1);
        for(int i = a; i <= b; i++)
            printf("%lld\n", (lint)(S[i].real + 0.5));
        putchar('\n');
    }
    return 0;
}
