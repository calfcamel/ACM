#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define clr(a,b) memset(a,b,sizeof a)
int tot;
int a[40];
int dp[40][2][2];
int cal(int n)
{
	if(n == 0) return 1;
	tot = 0;
	while(n)
	{
		a[tot++] = n & 1;
		n >>= 1;
	}
	clr(dp,0);
	std::reverse(a, a + tot);
	dp[0][1][0] = 1;
	dp[0][0][1] = 1;
	for(int i = 1; i < tot; i++)
	{
		dp[i][0][1] = dp[i - 1][0][1] + dp[i - 1][1][1];
		dp[i][1][1] = dp[i - 1][0][1];
		if(a[i] == 1)
		{
			dp[i][1][0] = dp[i - 1][0][0];
			dp[i][0][1] += dp[i - 1][0][0] + dp[i - 1][1][0];
		}
		if(a[i] == 0)
		{
			dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][1][0];
		}
	}
	int ret = dp[tot - 1][0][0] + dp[tot - 1][0][1] + dp[tot - 1][1][0] + dp[tot - 1][1][1];
	return ret;
}
int main()
{
	int _T;
	int n;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n", CAS, cal(n));
	}
}
/*
题目描述：
求0~n中有多少个整数k满足 (2 * k) ^ (3 * k) == k
数据范围：
*/