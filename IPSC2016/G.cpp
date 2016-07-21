#include <stdio.h>
#include <string.h>
int tot;
char ans[1005];
char str[1005];
void init()
{
    tot = 0;
}
void add(char ch)
{
    ans[tot++] = ch;
}
void display()
{
    if(!tot) add('0');
    ans[tot] = 0;
    puts(ans);
}
void run()
{
    scanf("%s",str);
    init();
    int n = strlen(str);
    for(int i = 0; i < n; i++)
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(tot == 0 && str[i] == '0') continue;
            add(str[i]);
        }
    display();
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
        run();
}
