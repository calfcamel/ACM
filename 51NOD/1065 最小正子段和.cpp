#include <stdio.h>
#include <set>
#include <algorithm>

int n;
int a[50004];
long long sum[50004];
std::multiset<long long> S;
long long ans = -1;

#define ccmin(x,y) {if(~x) x = std::min(x,y); else x = y;}

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    S.clear();
    for(int i = 1; i <= n; i++)
        S.insert(sum[i]);
    std::multiset<long long>::iterator it;
    for(int i = 1; i <= n; i++)
    {
        it = S.lower_bound(sum[i - 1] + 1);
        if(it != S.end())
            ccmin(ans, *it - sum[i - 1]);
        S.erase(S.find(sum[i]));
    }
    printf("%lld\n",ans);
}
