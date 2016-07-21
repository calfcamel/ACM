#include <stdio.h>

int main()
{
	int n,m,x;
	int ans = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		if(x <= m) ans += 1;
		else ans += 2;
	}
	printf("%d\n", ans);
}