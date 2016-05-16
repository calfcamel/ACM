#include <stdio.h>
#include <string.h>
char str[100];
int a[26];
int main()
{
	int n;
	scanf("%d",&n);
	if(n > 26)
	{
		puts("-1");
		return 0;
	}
	else
	{
		for(int i = 0; i < 26; i++)
			a[i] = 0;
		scanf("%d",str);
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			a[str[i] - 'a'] ++;
			if(a[str[i] - 'a'] > 1)
				ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}