#include <stdio.h>

char str[100];
const int a[12] = {54,157,54,157,54,157,300,481,300,481,300,481};
const int b[12] = {55,55,162,161,262,262,64,64,162,162,262,262};
int main()
{
    while(scanf("%s", str) != EOF)
    {
        if(str[0] == '.')
        {
            puts("done");
            return 0;
        }
        if(str[0] == ',')
        {
            puts("next");
            continue;
        }
        int flag = 0;
        if(str[0] == 'r') flag = 0;
        if(str[0] == 'y') flag = 1;
        if(str[0] == 'g') flag = 2;
        if(str[0] == 'o') flag = 3;
        if(str[0] == 'b') flag = 4;
        if(str[0] == 'p') flag = 5;
        if(str[1] == 'w') flag += 6;
        printf("%d %d\n", a[flag], b[flag]);
    }
}
