#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#define LL long long
const LL MOD = 1000000000 + 7;
const int MS = 100000;
bool chk[MS+1];
int totsu;
int ans;
int su[MS/8];
LL mul(LL a,LL b){return (a * b) % MOD;}
LL add(LL a,LL b){return (a + b) % MOD;}
LL kuai(LL a,LL b){
    LL ret = 1;
    while(b > 0){
        if(b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}
LL Ex_Gcd(LL a, LL b, LL &x, LL &y){
	LL r, t;
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	r = Ex_Gcd(b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return r;
}
LL niyuan(LL n){
    LL x;
    LL y;
    Ex_Gcd(n,MOD,x,y);
    x = (x % MOD + MOD) % MOD;
    return x;
}
void shai(){
	totsu = 0;
	memset(chk, false,sizeof chk);
	for (int i = 2; i <= MS; i++)
		if (!chk[i]){
		su[totsu++] = i;
		for (int j = i + i; j <= MS;j += i)
			chk[j] = true;
	}
}
int totp;
LL nump[200];
LL prime[200];
void fenjie(int n){
    totp = 0;
    for(int i = 0; i < totsu && n >= su[i]; i++){
        if(n % su[i] == 0){
            prime[totp] = su[i];
            nump[totp] = 0;
            while(n % su[i] == 0){
                n = n / su[i];
                nump[totp]++;
            }
            totp ++;
        }
    }
    if(n>1){
        prime[totp] = n;
        nump[totp] = 1;
        totp ++;
    }
}
int main(){
    int tt;
    scanf("%d",&tt);
    LL ans;
    LL x;
    LL y;
    LL ret;
    LL now;
    shai();
    for(int t=1;t<=tt;t++){
        scanf("%lld%lld",&x,&y);
        fenjie(x);
        for(int i=0;i<totp;i++)
            nump[i] *= y;
        ans = 1;
        for(int i=0;i<totp;i++){
            ret = 1;
            ret = (kuai(prime[i],nump[i] + 1) - 1 + MOD) % MOD;
            ret = mul(ret , niyuan(prime[i] - 1));
            ans = mul(ans , ret);
        }
        if(y == 0) ans = 1;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
