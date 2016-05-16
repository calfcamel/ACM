#include <stdio.h>
int a[30];
int ans;
int n,m,k;
void check(int st)
{
	//printf("chk %d\n", st);
	int now = 0;
	int need = 1;
	int ret = 0;
	for(int i = 0; i < n; i++) if(st &(1 << i))
	{
		ret ++;
		if(a[i] > k) 
			return;
		now += a[i];
		if(now > k)
		{
			need++;
			now = a[i];
		}
	}
	if(need > m) return;
	if(ans < ret) ans = ret;
}
int main()
{
	while(scanf("%d%d%d",&n,&k,&m))
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		int __END__ = 1 << n;
		ans = 0;
		for(int st = 0; st < __END__; st++)
		{
			check(st);
		}
		printf("%d\n", ans);
	}
}