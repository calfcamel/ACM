#include <stdio.h>
#include <set>
std::multiset<int> S;
int n;
int h,m;
int x;
long long ans;
int main()
{
	S.clear();
	ans = 0;
	int now = 0;
	scanf("%d%d%d",&n,&h,&m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		if(now > 0 && now + x > h)
		{
			ans++;
			ans += x / m;
			now = x % m;
		}
		else
		{
			now += x;
			ans += now / m;
			now = now % m;
		}
	}
	if(now) ans++;
	printf("%I64d\n", ans);
}