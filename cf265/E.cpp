#include <stdio.h>
#include <string.h>
char str[100005];
char s[500009];
int h[100005];
long long a[10];
long long b[10];
const long long inv10 = 1;
int main()
{
	scanf("%s",&str);
	int t = 0;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		h[i] = t;
		scanf("%s",s + t);
		t += strlen(s + t) + 1;
	}
	int x;
	char*p;
	int l;
	int length = 0;
	for(int i = 0; i < 10; i++)
	{
		a[i] = 10;
		b[i] = i;
	}
	for(int i = n - 1; i >= 0; i--)
	{
		p = s + h[i];
		x = p[0] - '0';
		p += 3;
		l = strlen(p);
		int tmp = 0;
		length = 1;
		if(l == 0)
		{
			a[x] = 1;
			b[x] = 0;
		}
		for(int j = l - 1; j >= 0; j++)
		{

		}
	}
}