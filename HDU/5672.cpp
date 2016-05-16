#include <stdio.h>
#include <string.h>

const int MAXN = 1000000 + 4;
char str[MAXN];
int k;
int n;
int now;
int cnt[26];
int j;
long long ans;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%d",&str,&k);
		n = strlen(str);
		j = 0;
		for(int i = 0; i < 26; i++) 
			cnt[i] = 0;
		now = 0;
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			while(now < k && j < n)
			{
				if(cnt[str[j] - 'a'] == 0) now++;
				cnt[str[j] - 'a']++;
				j++;
			}
			if(now < k) break;
			ans += n - j + 1;
			cnt[str[i] - 'a']--;
			if(cnt[str[i] - 'a'] == 0) now--;
		}
		printf("%lld\n", ans);
	}
}