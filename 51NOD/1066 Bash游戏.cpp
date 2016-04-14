#include <stdio.h>
int n,k;
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%d%d",&n,&k);
		if(n % (k + 1) == 0)
			printf("B\n");
		else
			printf("A\n");
	}
}