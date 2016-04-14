#include <cstdio>
#include <cstring>
#define clr(x,y) memset(x,y, sizeof (x))
typedef long long LL;
const int N = 1000000;
LL prime[N];
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
	printf("%lld\n", prime[10000]);
}