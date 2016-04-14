#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand((unsigned)time(NULL));
	int _T = 1000000;
	printf("%d\n", _T);
	for(int i = 0; i < _T; i++)
		printf("%d\n", rand() % 1000000000);
}