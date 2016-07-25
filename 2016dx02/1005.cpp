#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef map<pii, int>::iterator IT;
const ll mod = 1e9 + 7;
inline int abs(int a)
{
    if(a < 0) return -a;
    return a;
}
ll gcd(ll x, ll y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
int x[2000], y[2000];
ll two[2000];

int main() {
    int T;
    scanf("%d", &T);
    two[0] = 1;
    for(int i = 1; i < 2000; i++) two[i] = (two[i - 1] * 2LL) % mod;
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            map<pii, int>f;
            int cnt = 0;
            for(int j = i + 1; j < n; j++)
                {
                    int aa = x[j] - x[i], bb = y[j] - y[i];
                    if(aa == 0 && bb == 0)
                        cnt++;
                    else
                    {
                        if(aa < 0) {aa = -aa; bb = -bb;}
                        if(aa == 0 && bb < 0) bb = -bb;
                        ll g = gcd(abs(aa),abs(bb));
                        f[mp(aa / g, bb / g)]++;
                    }
                }
            ll tmp = 0;
            for(IT it = f.begin(); it != f.end(); it++) {
                //cout << "it "<< it->second << endl;
                tmp = two[cnt];
                tmp = tmp * ((two[it->second] + mod - 1) % mod) % mod;
                ans = (ans + tmp) % mod;
                //printf("add %d %lld\n",i,tmp);
            }
            //printf("add cnt %d %d\n", i, cnt);
            ans = (ans + two[cnt] - 1 + mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
