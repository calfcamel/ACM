#include <stdio.h>
#include <string.h>
#include <map>
const int MAXN = 100005;
struct node
{
	int nxt;
	int v;
}e[MAXN];
int h[MAXN];
#define clr(a,b) memset(a,b,sizeof(a))
int n;
int a[MAXN];
int f[MAXN];
int p[MAXN];
long long sum[MAXN];
std::map<long long, int> m;
int tote = 0;
void add(int x, int y)
{
	printf("add %d %d\n", x,y);
	p[y] = tote;
	e[tote].v = y;
	e[tote].nxt = h[x];
	h[x] = tote++;
}
int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	sum[0] = a[0];
	for(int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];
	int tot = 0;
	for(int i = 0; i < n; i++)
	{
		if(m[sum[i]] == 0) m[sum[i]] = ++tot;
	}
	clr(h,-1);
	for(int i = 0; i < n; i++)
	{
		printf("%lld ", sum[i]);
		add(m[sum[i]], i);
	}
	for(int i = 0; i < n; i++)
	{
		if(~e[p[i]].nxt)
			f[i] = e[e[p[i]].nxt].v;
		else
			f[i] = e[h[m[sum[i]]]].v;
	}
	for(int i = 0; i < n; i++)
		printf("%d %d\n", i, f[i]);
}
