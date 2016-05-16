#include <stdio.h>

int n,m;
int vis[17];
int a[100005];
int sum[17];
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS ++)
	{
		for(int i = 1; i <= 16; i++)
			vis[i] = 0;
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]] = 1;
		}
		m = 0;
		for(int i = 1; i <= 16; i++) if(vis[i])
			vis[i] = ++m;
		for(int i = 0; i < n; i++)
			a[i] = vis[a[i]];
		for(int i = 1; i <= m; i++)
			sum[i] = 0;
		for(int i = 0; i < n; i++)
			sum[a[i]]++;
		
	}
}