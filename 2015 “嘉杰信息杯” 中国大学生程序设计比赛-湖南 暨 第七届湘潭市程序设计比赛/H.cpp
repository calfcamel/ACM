#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define clr(a,b) memset(a,b,sizeof(a))
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)

const long long MOD = 1000000000 + 7;

int a[2][2001];
int n;
long long m;
long long b[100];
const int maxb = 39;
void init()
{
    b[0] = 1;
    for(int i = 1; i <= maxb; i++)
    {
        b[i] = b[i - 1] * 3;
        //printf("%d\t%lld\n", i, b[i]);
    }
}
char str[2005];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&n,&m);
        scanf("%s",str);
        int cur = 0;
        FOR(i,n)
            a[0][i] = str[i] - '0';
        while(m)
        {
            int x = maxb;
            while(b[x] > m) x--;
            FOR(i,n)
                a[cur ^ 1][i] = (a[cur][i] + a[cur][(b[x] + i) % n]) % 3;
            cur ^= 1;
            m -= b[x];
        }
        FOR(i,n)
        {
            printf("%d", a[cur][i]);
        }
        puts("");
    }
return 0;
}
