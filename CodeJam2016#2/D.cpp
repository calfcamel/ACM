#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

char str[1005];
char ans[2010];
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%s",&str);
		int n = strlen(str);
		char head = 0;
		int l = 1005;
		int r = 1005;
		for(int i = 0; i < n; i++)
		{
			if(head >= str[i])
			{
				head = str[i];
				ans[--l] = head;
			}
			else
			{
				ans[r++] = head;
			}
		}
		printf("Case #%d: \n", );
		for(int i = l; i < r; i++)
		{
			putchar(ans[i]);
		}
		puts("");
	}
}