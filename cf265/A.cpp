#include <stdio.h>
#define FOR(i,x) for(int i = 0,__END__ = (int)(x); i < __END__;i++)
#define FORR(i,x) for(int i = 1,__END__ = (int)(x); i <= __END__;i++)
#define FORR(i,y,x) for(int i = (int)(y),__END__ = (int)(x); i <= __END__;i++)
char str[105];
int main()
{
	int n;
	scanf("%d%s",&n,&str);
	int ans = 0;
	FOR(i,n)
	{
		if(str[i] == '1')
		{
			ans++;
		}
		if(str[i] == '0')
		{
			ans++;
			break;
		}
	}
	printf("%d\n", ans);
}