#include <stdio.h>
void put(int x)
{
	if(x == 0) printf("ling");
	if(x == 1) printf("yi");
	if(x == 2) printf("er");
	if(x == 3) printf("san");
	if(x == 4) printf("si");
	if(x == 5) printf("wu");
	if(x == 6) printf("liu");
	if(x == 7) printf("qi");
	if(x == 8) printf("ba");
	if(x == 9) printf("jiu");
	if(x == 10) printf("shi");
	if(x == 100) printf("bai");
}
void gao(int n)
{
	if(n % 100 == 0 && n >= 100)
	{
		put(n / 100);
		put(100);
		puts("");
		return;
	}
	if(n >100 && n % 100 > 10 && n % 100 < 20)
	{
		put(n / 100);
		put(100);
		put(1);
		put(10);
		put(n % 10);
		puts("");
		return;
	}
	if(n >10 && n < 20)
	{
		put(10);
		put(n % 10);
		puts("");
		return;
	}
	if(n > 100 && n % 100 == 10)
	{
		put(n/100);
		put(100);
		put(1);
		put(10);
		puts("");
		return;
	}
	if(n == 10)
	{
		put(10);
		puts("");
		return;
	}
	if(n < 10)
	{
		put(n);
		puts("");
		return;
	}
	if(n == 100)
	{
		put(1);
		put(100);
		puts("");
		return;
	}
	if(n > 100)
	{
		put(n / 100);
		put(100);
		n = n % 100;
		if(n < 10)
		{
			put(0);
		}
		gao(n);
		return;
	}
	put(n / 10);
	put(10);
	if(n % 10)
		put(n % 10);
		puts("");
}
void gao2(int n)
{
	if(n <= 10)
	{
		put(n);
		puts("");
		return;
	}
	if(n < 20)
	{
		//put(1);
		put(10);
		put(n % 10);
		puts("");
		return;
	}
	if(n < 100)
	{
		put(n / 10);
		put(10);
		n %= 10;
		if(n)
			put(n);
		puts("");
		return;
	}
	put(n / 100);
	put(100);
	n %= 100;
	if(n == 0){
		puts("");
		return;
	}
	if(n <= 9)
	{
		put(0);
		put(n);
		puts("");
		return;
	}
		put(n / 10);
		put(10);
		n %= 10;
		if(n)
			put(n);
		puts("");
		return;
}
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		gao2(n);
	}
}