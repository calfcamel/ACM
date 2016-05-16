#include <stdio.h>
#define FOR(i,x) for(int i = 0,__END__ = (int)(x); i < __END__;i++)
#define FORR(i,x) for(int i = 1,__END__ = (int)(x); i <= __END__;i++)
#define FORR(i,y,x) for(int i = (int)(y),__END__ = (int)(x); i <= __END__;i++)
char s[1005];
char ss[1005];
int n,p;
int add(int x)
{
	s[x]++;
	while(s[x] >= 'a' + p)
	{
		s[x] = 'a';
		x--;
		if(x < 0) return -1;
		s[x]++;
	}
	return x;
}
int chk[100];
int tryto(int x)
{
	for(int d = 0; d < 26; d++)
	{
		if(add(x) == -1)
			return 0;
		int flag = 1;
		for(int i = 0; i <= x; i++)
		{
			if(i - 2 >= 0 && s[i] == s[i - 2]) flag = 0;
			if(i - 1 >= 0 && s[i] == s[i - 1]) flag = 0;
		}
		if(!flag)
			continue;
		char ch;
		for(int i = x + 1; i < n; i++)
		{
			chk[0] = 0;
			chk[1] = 0;
			if(i - 2 >= 0)
				chk[s[i - 2] - 'a'] = 1;
			if(i - 1 >= 0)
				chk[s[i - 1] - 'a'] = 1;
			ch = 'a';
			if(chk[0])
			{
				ch++;
				if(chk[1])
					ch++;
			}
			s[i] = ch;
			if(s[i] >= 'a' + p) flag = 0;
		}
		if(flag)
		{
			//printf("%d %d\n", x, d);
			puts(s);
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&p);
	scanf("%s",s);

	for(int j = n - 1; j >= 0; j--)
	{
		for(int i = 0; i <= n; i++) ss[i] = s[i];
		if(tryto(j))
			return 0;
		for(int i = 0; i <= n; i++) s[i] = ss[i];
	}
	puts("NO");
	//printf("%d\n", ans);
}