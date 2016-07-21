#include <stdio.h>

char ch;

inline void chk(char ch)
{
    int flag = 0;
    if(ch >= '0' && ch <= '9') flag = 1;
    if(ch >= 'A' && ch <= 'Z') flag = 1;
    if(ch >= 'A' && ch <= 'Z') flag = 1;
    if(flag) printf("%c",ch);
}

int main()
{
    freopen("i1.in", "rb", stdin);
    while(scanf("%c", &ch) == 1)
    {
        chk(ch);
    }
    return 0;
}
