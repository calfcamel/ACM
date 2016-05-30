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

#define all(v) v.begin(), v.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = 10000 + 4;
int n;
vector<pii> lv,rv,v,L,R;
priority_queue<pii> Q;
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(cas,_T)
    {
        scanf("%d",&n);
        lv.clear();
        rv.clear();
        L.clear();
        R.clear();
        int x,y,z,d;
        FOR(i,n)
        {
            scanf("%d%d%d%d",&x,&y,&z,&d);
            if(y - z > x + z) continue;
            if(d == -1) lv.PB(MP(y - z, x + z));
            else rv.PB(MP(y - z, x + z));
        }
        sort(all(rv));
        sort(all(lv));

        v.clear();
        FOR(i,lv.size())
        {
            v.PB(MP(lv[i].BB, 1));
            v.PB(MP(lv[i].AA - 1,-1));
        }
        sort(all(v));
        int now = 0;
        for(int i = (int)v.size() - 1; i >= 0; i--)
        {
            if(v[i].BB == 1) now++; else now--;
            if(now >= 1)
            {
                L.PB(MP(v[i].AA, now));
            }
        }

        v.clear();
        FOR(i,rv.size())
        {
            v.PB(MP(rv[i].AA, 1));
            v.PB(MP(rv[i].BB + 1, -1));
        }
        sort(all(v));
        now = 0;
        FOR(i,v.size())
        {
            if(v[i].BB == 1) now++; else now--;
            if(now >= 1)
            {
                R.PB(MP(v[i].AA, now));
            }
        }
        /*
        printf("LV: ");
        FOR(i,lv.size())
            printf("[%d,%d] ", lv[i].AA, lv[i].BB);
        puts("");
        printf("RV: ");
        FOR(i,rv.size())
            printf("[%d,%d] ", rv[i].AA, rv[i].BB);
        puts("");
        printf("L: ");
        FOR(i,L.size())
            printf("[%d,%d] ", L[i].AA, L[i].BB);
        puts("");
        printf("R: ");
        FOR(i,R.size())
            printf("[%d,%d] ", R[i].AA, R[i].BB);
        puts("");
        */
        int ans = 0;
        while(!Q.empty()) Q.pop();
        FOR(i,R.size())
        {
            Q.push(MP(R[i].BB, R[i].AA));
        }
        if(!Q.empty()) ans = Q.top().AA;
        int tmp;
        for(int i = L.size() - 1; i >= 0; i--)
        {
            tmp = L[i].BB;
            while(!Q.empty() && Q.top().BB > L[i].AA) Q.pop();
            if(!Q.empty()) tmp += Q.top().AA;
            cmax(ans, tmp);
        }
        printf("Case #%d:\n%d\n", cas,ans);
    }
    return 0;
}
