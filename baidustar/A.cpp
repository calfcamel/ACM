#include <stdio.h>
#include <string.h>

char str[100005];
int sum[100005];
const int mod = 9973;
const int N = mod + 10;
int inv[N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < mod; i++)
        inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
}
int main()
{
	int q;
	init();
	int ans;
	while(scanf("%d",&q)!= EOF)
	{
		scanf("%s",str);
		int n = strlen(str);
		sum[0] = 1;
		for(int i = 0; i < n; i++)
			sum[i + 1] = sum[i] * ((int)(str[i] - 28)) % mod;
		int a,b;
		for(int i = 0; i < q; i++)
		{
			scanf("%d%d",&a,&b);
			if(a > b){
				int t = a;
				a = b;
				b = t;
			}
			if(b < n + 1 && a > 0) ans = sum[b] * inv[sum[a - 1]] % mod;
			printf("%d\n", ans);
		}
	}
	return 0;
}