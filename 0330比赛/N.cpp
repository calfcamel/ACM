#include <stdio.h>

typedef unsigned int u32;
const u32 get11 = (u32)4292870144;
u32 a[32];
void putu32(u32 x)
{
	printf(" u32 =");
	u32 p = 1u << 31u;
	for(int i = 0; i < 32; i++)
	{
		if(i % 8 == 0) printf(" ");
		if(x & p) printf("1");
		else printf("0");
		p >>= 1;
	}
	puts("");
}
int main()
{
	for(int i = 0; i < 32; i++)
		a[i] = 1u << (u32)i;
	//for(int i = 0; i < 32; i++) printf("%d %u\n", i,a[i]);
	//printf("%u\n", get11);
	int _T;
	scanf("%d",&_T);
	while(_T--)
	{
		u32 n;
		scanf("%u",&n);
		u32 x = n & ((1 << 16) - 1);
		u32 y = n >> 16;
		if(y > x) y = y - x;
		else y = y + (1 << 16) - x;
		//printf("%u\n", (y << 16) + x);
		n = (y << 16) + x;
		u32 get;
		get = 0u;
		for(int i = 32 - 11; i < 32; i++) get += a[i];
		x = n & get;
		y = n ^ (x >> 11);
		get = 0u;
		for(int i = 32 - 11 - 11; i < 32 - 11; i++) get += a[i];
		y = y & get;
		u32 ans = y + x;
		x = ans;
		y = n ^ (ans >> 11);
		ans = y;
		n = ans;
		printf("n2 = %u\n", n);
		putu32(n);
		u32 init;
		get = 0u;
		for(int i = 0; i < 3; i++) get += a[i];
		x = n & get;
		init = x;
		ans = init;
		get = 0u;
		putu32(ans);
		for(int i = 3; i < 6; i++) get += a[i];
		y = n & get; y >>= 3;
		if(y > x) y -= x;
		else y = (y +(1 << 3)) - x;
		ans = init + (y << 3);
		putu32(ans);
		get = 0u;
		for(int i = 3; i < 3 + 6; i++) get += a[i];
		y = n & get; y >>= 3;
		if(y > x) y -= x;
		else y = (y +(1 << 6)) - x;
		ans = init + (y << 3);
		putu32(ans);
		get = 0u;
		for(int i = 3; i < 3 + 12; i++) get += a[i];
		y = n & get; y >>= 3;
		if(y > x) y -= x;
		else y = (y +(1 << 12)) - x;
		ans = init + (y << 3);
		putu32(ans);
		get = 0u;
		for(int i = 3; i < 3 + 24; i++) get += a[i];
		y = n & get; y >>= 3;
		if(y > x) y -= x;
		else y = (y +(1 << 24)) - x;
		ans = init + (y << 3);
		putu32(ans);
		y = n >> 3;
		x = ans;
		if(y > x) y -= x;
		else y = (y +(1 << 24)) - x;
		ans = init + (y << 3);
		n = ans;
		putu32(ans);
	}

}