#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#define clr(a,b) memset(a,b,sizeof a)
const long long MOD = 100000007;
long long dp[2][1001];
long long g[1001][1001];
int gcd ( int a, int b ) { int c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }
int main()
{
	for(int i = 0; i <= 1000; i++)
		for(int j = i; j <= 1000; j++)
			g[i][j] = g[j][i] = gcd(i,j);
	int _T;
	scanf("%d",&_T);
	int cur;
	int n;
	int x;
	while(_T--)
	{
		scanf("%d",&n);
		clr(dp, 0);
		cur = 0;
		for(int i = 0; i < n; i++)
		{
			clr(dp[cur ^ 1], 0);
			scanf("%d",&x);
			for(int j = 0; j < n; j++) if(dp[cur][j])
			{
				dp[cur ^ 1][g[x][j]] += dp[cur][j];
				if(dp[cur ^ 1][g[x][j]] >= MOD)
					dp[cur ^ 1][g[x][j]] -= MOD;
			}
			dp[cur ^ 1][x]++;
			if(dp[cur ^ 1][x] >= MOD) dp[cur ^ 1][x] -= MOD;
			cur ^= 1;
 		}
 		long long ans = 0;
 		for(long long i = 0; i <= 1000; i++)
 			ans = (ans + i * dp[cur][i]) % MOD;
 		std::cout << ans << std::endl;
	}
}