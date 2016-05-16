#include <stdio.h>

int tot = 0;
int a[100000];
int b[10];

int main()
{
	for(int i = 1; i <= 1000; i++)
	{
		if(tot > 1000) break;
		int t = i;
		int tb = 0;
		while(t)
		{
			b[tb++] = t % 10;
			t /= 10;
		}
		for(int i = tb-1; i >= 0; i--)
			a[tot++] = b[i];
	}
	int n;
	scanf("%d",&n);
	printf("%d\n", a[n-1]);
}