#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-14

const int maxn=1000010;
char str[maxn];//原字符串
char tmp[maxn<<1];//转换后的字符串
int Len[maxn<<1];
//转换原始串
int INIT(char *st)
{
    int i,len=strlen(st);
    tmp[0]='@';//字符串开头增加一个特殊字符，防止越界
    for(i=1; i<=2*len; i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=st[i/2];
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='$';//字符串结尾加一个字符，防止越界
    tmp[2*len+3]=0;
    return 2*len+1;//返回转换字符串的长度
}
//Manacher算法计算过程
int MANACHER(char *st,int len)
{
    int mx=0,ans=0,po=0;//mx即为当前计算回文串最右边字符的最大值
    for(int i=1; i<=len; i++)
    {
        if(mx>i)
            Len[i]=min(mx-i,Len[2*po-i]);//在Len[j]和mx-i中取个小
        else
            Len[i]=1;//如果i>=mx，要从头开始匹配
        while(st[i-Len[i]]==st[i+Len[i]])
            Len[i]++;
        if(Len[i]+i>mx)//若新计算的回文串右端点位置大于mx，要更新po和mx的值
        {
            mx=Len[i]+i;
            po=i;
        }
        ans=max(ans,Len[i]);
    }
    return ans-1;//返回Len[i]中的最大值-1即为原串的最长回文子串额长度
}
const long long MOD = 1000000007;
inline void upd(long long &x, long long y)
{
    x += y;
    if(x > MOD) x -= MOD;
    if(x < 0) x += MOD;
}
long long f[maxn << 1];
long long cf[maxn << 1];
long long g[maxn << 1];
long long cg[maxn << 1];
long long a[maxn << 1];
long long b[maxn << 1];
const long long inv2 = (MOD + 1) / 2;
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=INIT(str);
        MANACHER(tmp,len);
        //puts(tmp);
        //for(int i = 0; i < len; i++)
        //    printf("%d ", Len[i]);
        //puts("");
        for(int i = 1; i <= len; i++)
            f[i] = cf[i] = g[i] = cg[i] = 0;
        for(int i = 1,l; i < len; i++)
        {
            l = Len[i] - 1;
            //f[i - l] += i + l;
            cf[i - l] ++;
            //g[i] += i;
            cg[i] ++;
            upd(f[i - l], i + l);
            upd(g[i],i);
        }
        long long cnt;
        long long num;
        num = 0;
        cnt = 0;
        for(int i = 1; i < len; i++)
        {
            //num += f[i];
            //cnt += cf[i];
            //a[i] = num >> 1;
            //num -= g[i];
            //cnt -= cg[i];
            //num -= cnt;
            upd(num,f[i]);
            upd(cnt, cf[i]);
            a[i] = num * inv2 % MOD;
            upd(num, -g[i]);
            upd(cnt, -cg[i]);
            upd(num, -cnt);
        }
        //for(int i = 1; i < len; i++) if(!(i & 1))
        //    printf("%lld ", a[i]);
        //puts("");

        for(int i = 1; i <= len + 1; i++)
            f[i] = cf[i] = g[i] = cg[i] = 0;
        for(int i = len,l; i >= 1; i--)
        {
            l = Len[i] - 1;
            //f[i + l] += i - l;
            cf[i + l] ++;
            //g[i] += i;
            cg[i]++;
            upd(f[i + l], i - l);
            upd(g[i],i);
        }
        cnt = 0;
        num = 0;
        //printf("len = %d\n",len);
        for(int i = len + 1; i >= 1; i--)
        {
            //num += f[i];
            //cnt += cf[i];
            //b[i] = num >> 1;
            //num -= g[i];
            //cnt -= cg[i];
            //num += cnt;
            upd(num,f[i]);
            upd(cnt, cf[i]);
            b[i] = num * inv2 % MOD;
            upd(num, -g[i]);
            upd(cnt, -cg[i]);
            upd(num,cnt);
        }
        //for(int i = 1; i < len; i++) if(!(i & 1))
        //    printf("%lld ", b[i]);
        //puts("");
        long long ans = 0;
        for(int i = 2; i + 2 < len; i += 2)
                ans += a[i + 2] * b[i] % MOD;
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}
