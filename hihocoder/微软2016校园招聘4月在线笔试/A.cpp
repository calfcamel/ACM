#include <stdio.h>

int n,p,w,h;
int a[1001];
int chk(int x)
{
	int ww = w / x;
	int hh = h / x;
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += (a[i] + ww - 1) / ww;
	int ret = (sum + hh - 1) / hh;
	return ret;
}
void tryto()
{
	int l = 1;
	int r = w;
	if(h < r) r = h;
	int mid;
	while(l < r)
	{
		mid = (l + r + 1) / 2;
		if(chk(mid) <= p)
			l = mid;
		else 
			r = mid - 1;
	}
	printf("%d\n", l);
}
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 0; CAS < _T; CAS++)
	{
		scanf("%d%d%d%d",&n,&p,&w,&h);
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		tryto();
	}
}