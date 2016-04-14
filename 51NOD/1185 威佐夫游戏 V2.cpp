#include <stdio.h>
#include <math.h>
long long a,b;
int main()
{
	int _T;
	long double lb5 = 5;
	long double lb2 = 2;
	long double lb1 = 1;
	long double p = (sqrt(lb5) + lb1) / lb2;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%lld%lld",&a,&b);
		if(a > b)
		{
			long long t = a;
			a = b;
			b = t;
		}
		long long k = a / p;
		if((a == (long long)(k * p) && b == a + k) || (a == (long long)((k + 1) * p) && b == a + k + 1))
			printf("B\n");
		else 
			printf("A\n");
	}
}