#include <stdio.h>
#include <string.h>

int a[10];
char str[1000006];
char s[1000006];
int b[10];
char ans[10000006];
char ans2[10000006];
char ans1[10000006];
int main()
{
	for(int i = 0; i < 10; i++)
	 	a[i] = 0;
	scanf("%s",&str);
	int l = strlen(str);
	for(int i = 0; i < l; i++)
		a[str[i] - '0'] ++;
	scanf("%s",&s);
	int ls = strlen(s);
	for(int i = 0; i < ls; i++)
		a[s[i] - '0'] --;
	if(l == 2)
	{
		puts(s);
		return 0;
	}
	int have;
	int not0;
	int tmpi;
	int lans;
	for(int i = 1; i < l; i++)
	{
		have = 1;
		not0 = 0;
		tmpi = i;
		lans = 0;
		while(tmpi)
		{
			a[tmpi % 10]--;
			tmpi /= 10;
			lans++;
		}
		for(int j = 0; j < 10; j++)
			if(a[j] < 0) have = 0;
		for(int j = 1; j < 10; j++)
			if(a[j] > 0) not0 = 1;
		if(s[0] != '0') not0 = 1;
		if(have && not0 && l - lans == i)
		{
			//printf("%d\n", i);
			lans = 0;
			not0 = 0;
			for(int i = 1; i < 10; i++)
				if(a[i] > 0) not0 = 1;
			if(!not0)
			{
				lans = 0;
				for(int i = 0; i < ls; i++)
					ans[lans++] = s[i];
				for(int i = 0; i < 10; i++)
					for(int j = 0; j < a[i]; j++)
						ans[lans++] = i + '0';
				ans[lans] = 0;
				printf("%s\n", ans);
				return 0;
			}
			else
			{
				lans = 0;
				for(int i = 0; i < ls; i++)
					ans[lans++] = s[i];
				for(int i = 0; i < 10; i++)
					for(int j = 0; j < a[i]; j++)
						ans[lans++] = i + '0';
				ans[lans] = 0;
				// END ans
				int lans1 = 0;
				int numequal = 0;
				char ch = s[0];
				int numch = ch - '0';
				char bigch;
				int big = 0;
				for(int i = 0; i < ls; i++)
					if(ch == s[i]) numequal++;
					else
					{
						if(s[i] > ch)
						{
							big = 1;
							bigch = s[i];
						}
						break;
					}
				// gethead
				for(int i = 1; i < 10; i++) if(a[i] > 0)
				{
					ans1[lans1++] = i + '0';
					a[i]--;
					break;
				}
				int lans2 = 0;
				ans2[lans2++] = ans1[0];

				for(int i = 0; i < 10; i++)
				{
					for(int j = 0; j < a[i]; j++)
						ans1[lans1++] = i + '0';
					if(i == numch)
					{
						for(int j = 0; j < ls; j++)
							ans1[lans1++] = s[j];
					}
				}
				ans1[lans1] = 0;
				for(int i = 0; i < 10; i++)
				{
					if(i == numch)
					{
						for(int j = 0; j < ls; j++)
							ans2[lans2++] = s[j];
					}
					for(int j = 0; j < a[i]; j++)
						ans2[lans2++] = i + '0';
				}
				ans2[lans2] = 0;
				//puts(ans);
				//puts(ans1);
				//puts(ans2);
				if(s[0] == '0')
				{
					for(int i = 0; i < lans1;i++)
					{
						ans[i] = ans1[i];
					}
				}
				if(strcmp(ans,ans1) > 0)
				{
					for(int i = 0; i < lans1;i++)
					{
						ans[i] = ans1[i];
					}
				}
				if(strcmp(ans,ans2) > 0)
				{
					for(int i = 0; i < lans2;i++)
					{
						ans[i] = ans2[i];
					}
				}
				puts(ans);
			}
			return 0;
		}
		tmpi = i;
		while(tmpi)
		{
			a[tmpi % 10]++;
			tmpi /= 10;
		}
	}

}