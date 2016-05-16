#include <stdio.h>

const int N = 10000;
int prime[N];
bool check[N];
int totp;
void Eular()
{
	clr(check,false);
    totp = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[totp++] = i;
		for (int j = 0; j < totp; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int main()
{
	Eular();
	int n;
	while(scanf("%d",&n)!= EOF)
	{
		int ans = 1;
		
	}
}