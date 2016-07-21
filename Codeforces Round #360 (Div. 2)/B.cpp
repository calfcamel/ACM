#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[1000001];
int n;
int main()
{
    scanf("%s",s);
    n = strlen(s);
    printf("%s",s);
    reverse(s,s+n);
    puts(s);
}
