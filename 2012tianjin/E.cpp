#include <stdio.h>
#include <string.h>
#include <math.h>

int f[129];
inline void initset()
{
    for(int i = 0; i <= 128; i++)
        f[i] = i;
}

int getf(int x)
{
    if(f[x] == x) return x;
    return f[x] = getf(f[x]);
}

inline void addset(int x, int y)
{
    int fx = getf(x);
    int fy = getf(y);
    f[fx] = fy;
}

int n,d;
int bin[129];
int boo[129][129];
int dis[129][129];
int x[129],y[129];

inline int sqr(int x)
{
    return x * x;
}
inline int getdis(int i, int j)
{
    int ret = ceil(sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])));
    return ret;
}
void add(int i, int j)
{
    if(boo[i][j] == 2 && (bin[i] | bin[j])) {addset(i,j);return;}
    if(boo[i][j] == 1 && (bin[i] & bin[j])) {addset(i,j);return;}
}
int main()
{
    while(scanf("%d%d",&n,&d) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i = 1; i <= n; i++)
            bin[i] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = getdis(i,j);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                boo[i][j] = 0;
                if(dis[i][j] <= d) boo[i][j] = 1;
                if(dis[i][j] * 2 <= d) boo[i][j] = 2;
            }
        initset();
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(boo[i][j]) addset(i,j);
        int flag = 0;
        for(int i = 1; i <= n; i++)
            if(getf(1) != getf(i))
                flag = 1;
        if(flag == 1)
            puts("-1");
        else
        {
            for(int i = n; i >= 2; i--)
            {
                bin[i] = 0;
                flag = 0;
                initset();
                for(int j = 1; j <= n; j++)
                    for(int k = j + 1; k <= n; k++)
                        add(j,k);
                for(int j = 1; j <= n; j++)
                    if(getf(1) != getf(j))
                        flag = 1;
                bin[i] = flag;
            }
            while(bin[n] == 0) n--;
            for(int i = n; i >=1; i--)
                printf("%d",bin[i]);
            puts("");
        }
    }
}
