#include <stdio.h>
const double e = 2.718281828459;
int gcd(int a,int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}
double get(double n, int k)
{
	double dk = k;
	n /= dk;
	double ret = 1.0;
	for(int i = 0; i < k; i++)
		ret *= n;
	return ret;
}
double my_pow(double n, int k)
{
	double dk = k;
	n /= dk;
	double ret = 1.0;
	while(k)
	{
		if(k & 1) ret *= n;
		k >>= 1;
		n *= n;
	}
	return ret;
}
int cal(int n)
{
	if(n % 100 == 0) printf("cal %d\n", n);
	double Max = n;
	int Max_k = 1;
	double tmp;
	/*for(int k = 2; k < n; k++)
	{
		tmp = my_pow(n,k);
		if(tmp > Max)
		{
			Max = tmp;
			Max_k = k;
		}
	}
	int k = Max_k;*/
	double dn = n;
	int k = (int)(dn / e + 0.5);
	int g = gcd(n,k);
	k /= g;
	while(k % 2 == 0) k /= 2;
	while(k % 5 == 0) k /= 5;
	if(k == 1) return -n;
	else return n;
}
int main()
{
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 5; i <= n; i++)
		ans += cal(i);
	printf("%d\n", ans);
}

/*
定义g(n,k) = (n / k) ^ k;
f(n) = max{g(n,k)} (1<=k<=n);
D(n) = { -n (f(n)是有限小数)
		 n (f(n)是无限小数)
给定 n
求 sum{D(i)} ( 5 <= i <= n)
范围
5 <= n <= 10000
*/

///备注：这道题在n = 10000 时已经验证是对的。