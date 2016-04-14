#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

long long k,c,s;
inline long long zou(long long now, long long x)
{
	if(x > k) x = k;
	return now * k + x - k;
}
std::vector<long long> v;
int main()
{
	int _T;
	std::cin >> _T;
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		std::cin >> k >> c >> s;
		v.clear();
		long long now = 0;
		while(now < k)
		{
			long long tmp = 1;
			for(int i = 0; i < c; i++)
			{
				now++;
				tmp = zou(tmp, now);
			}
			v.push_back(tmp);
		}
		printf("Case #%d:", CAS);
		if(v.size() > s)
			puts(" IMPOSSIBLE");
		else
		{
			for(int i = 0; i < v.size(); i++)
				printf(" %lld", v[i]);
			puts("");
		}
	}
}