#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;

//#pragma comment(linker, "/STACK:102400000,102400000")

#define MP3(x,y,z) make_pair(make_pair(x,y),z)
#define MP make_pair
#define AA first
#define XX first.first
#define YY first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl

const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = 100000 + 5;
pii a[500000];
int main()
{
    srand(time(NULL));
    for(int i = 0; i < 500000; i++)
    {
        int x = rand() % 50000 + 1;
        int y = rand() % 50000 + 1;
        a[i].AA = x;
        a[i].BB = y;
    }
    sort(a, a + 500000);
    int tot = unique(a, a + 500000) - a;
    int T = 10;
    printf("%d\n",T);
    while(T--)
    {
        int r = 50000;
        int c = 50000;
        int n = 50000;
        random_shuffle(a,a + tot);
        printf("%d %d %d\n",r,c,n);
        FOR(i,n) printf("%d %d\n", a[i].AA, a[i].BB);
    }
    return 0;
}
