#include <stdio.h>
#define FOR(i,x) for(int i = 0,__END__ = (int)(x); i < __END__;i++)
#define FORR(i,x) for(int i = 1,__END__ = (int)(x); i <= __END__;i++)
#define FORR(i,y,x) for(int i = (int)(y),__END__ = (int)(x); i <= __END__;i++)
int a[1005];
int main()
{
	int n;
	scanf("%d",&n);
	FOR(i,n) scanf("%d",&a[i]);
	int st = 0;
	int ans = 0;
	int bef = -100;
	for(int i = 0; i < n; i++) if(a[i] == 1)
	{
		if(st == 0)
		{
			ans += 1;
			st = 1;
		}
		else
		if(i - bef > 2)
			ans += 2;
		else
			ans += i - bef;
		bef = i;
	}
	printf("%d\n", ans);
}