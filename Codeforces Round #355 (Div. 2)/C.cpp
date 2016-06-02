#include <stdio.h>
#include <string.h>
char str[100005];
inline int getnum(char ch)
{
	if(ch == '_') return 0;
	if(ch == '-') return 1;
	if(ch <= 'z' && ch >= 'a') return 6 - __builtin_popcount(36 + ch - 'a');
	if(ch <= 'Z' && ch >= 'A') return 6 - __builtin_popcount(10 + ch - 'A');
	return 6 - __builtin_popcount(ch - '0');
}
long long mod = 1000000007;
long long mypow(long long b)
{
	long long a = 3;
	long long ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//for(int i = 0; i <= 63; i++)
	//	printf("get %d = %d\n", i, 6 - __builtin_popcount(i));
	//printf("%d %d\n",getnum('V'), getnum('z'));
	scanf("%s",str);
	int n = strlen(str);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cnt += getnum(str[i]);
	}
	cnt = mypow(cnt);
	printf("%d\n",cnt);
}