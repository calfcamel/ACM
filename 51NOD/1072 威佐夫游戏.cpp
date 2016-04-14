#include <stdio.h>
#include <math.h>
int a,b;
int main()
{
	int _T;
	double p = (sqrt(5.) + 1.) / 2.;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%d%d",&a,&b);
		if(a > b)
		{
			int t = a;
			a = b;
			b = t;
		}
		int k = a / p;
		if((a == int(k * p) && b == a + k) || (a == int((k + 1) * p) && b == a + k + 1))
			printf("B\n");
		else 
			printf("A\n");
	}
}