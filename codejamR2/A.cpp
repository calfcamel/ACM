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
int a[3];
int n;
int R,P,S;
int b[3];
int chk()
{
    FORR(i,n-1)
    {
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];
        b[0] += a[1];
        b[1] += a[2];
        b[2] += a[0];
        a[0] = b[0];
        a[1] = b[1];
        a[2] = b[2];
    }
    if(a[0] == R && a[1] == P && a[2] == S)
        return 1;
    return 0;
}
char s[(1 << 12) + 10];
char s2[(1 << 12) + 10];
char t[(1 << 12) + 10];
int ls,lt;
void shuchu()
{
    ls = 2;
    FORR(i,n - 1)
    {
        lt = 0;
        FOR(j,ls)
        {
            if(s[j] == 'R'){t[lt++] = 'R'; t[lt++] = 'S';}
            if(s[j] == 'P'){t[lt++] = 'P'; t[lt++] = 'R';}
            if(s[j] == 'S'){t[lt++] = 'P'; t[lt++] = 'S';}
        }
        t[lt] = 0;
        ls = lt;
        swap(s,t);
    }
    swap(s,s2);
    //puts(s);
}
void shuchu2()
{
    ls = 2;
    FORR(i,n - 1)
    {
        lt = 0;
        FOR(j,ls)
        {
            if(s[j] == 'R'){t[lt++] = 'R'; t[lt++] = 'S';}
            if(s[j] == 'P'){t[lt++] = 'P'; t[lt++] = 'R';}
            if(s[j] == 'S'){t[lt++] = 'P'; t[lt++] = 'S';}
        }
        t[lt] = 0;
        ls = lt;
        swap(s,t);
    }
    if(strcmp(s,s2) > 0) swap(s,s2);
    puts(s);
    //puts(s2);
    //swap(s,s2);
    //puts(s);
}
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(cas, _T)
    {
        scanf("%d%d%d%d",&n,&R,&P,&S);
        printf("Case #%d: ",cas);
        if(n == 1)
        {
            if(R == 2 || P == 2 || S == 2)
                puts("IMPOSSIBLE");
            else
            {
                if(P) printf("P");
                if(R) printf("R");
                if(S) printf("S");
                puts("");
            }
            continue;
        }
        else
        {
            a[0] = 1;
            a[1] = 1;
            a[2] = 0;
            if(chk())
            {
                s[0] = 'P';
                s[1] = 'R';
                s[2] = 0;
                shuchu();
                s[0] = 'R';
                s[1] = 'P';
                s[2] = 0;
                shuchu2();
                continue;
            }
            a[0] = 0;
            a[1] = 1;
            a[2] = 1;
            if(chk())
            {
                s[0] = 'P';
                s[1] = 'S';
                s[2] = 0;
                shuchu();
                s[0] = 'S';
                s[1] = 'P';
                s[2] = 0;
                shuchu2();
                continue;
            }
            a[0] = 1;
            a[1] = 0;
            a[2] = 1;
            if(chk())
            {
                s[0] = 'R';
                s[1] = 'S';
                s[2] = 0;
                shuchu();
                s[0] = 'S';
                s[1] = 'R';
                s[2] = 0;
                shuchu2();
                continue;
            }
        }
        puts("IMPOSSIBLE");
    }
    return 0;
}
