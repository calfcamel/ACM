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
int totchk;
int achk[40];
int chk(int n)
{
	totchk = 0;
	while(n)
	{
		achk[totchk++] = n & 1;
		n >>= 1;
	}
	for(int i = 0; i < totchk - 1; i++)
		if(achk[i] == 1 && achk[i + 1] == 1) return 0;
	return 1;
}
int cal_baoli(int n)
{
	int ret = 0;
	for(int i = 0; i <= n; i++)
	{
		if(chk(i)) ret++;
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i <= n; i++)
	{
		//if(cal(i) != cal_baoli(i))
		{
			printf("n = %d cal = %d baoli = %d\n", i, cal(i), cal_baoli(i));
		}
	}
	puts("Succeed");
}
//Li@Qingyu#920118
/*
题目描述：
求0~n中有多少个整数k满足 (2 * k) ^ (3 * k) == k
数据范围：
case < 1000000
0 <= n <= 10^9
样例输入
5
0
1
2
3
4
样例输出
Case #1: 1
Case #2: 2
Case #3: 3
Case #4: 3
Case #5: 4

*/