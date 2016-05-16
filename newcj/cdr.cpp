#include <stdio.h>

int main()
{
	double ans = 1.0;
	ans *= .8;
	ans *= 1.0 - .125;
	ans *= 1.0 - .1;
	ans *= 1.0 - .1;
	ans *= 1.0 - .08;
	ans *= 1.0 - .08;
	ans *= 1.0 - .08;
	ans *= 1.0 - .08;
	printf("%.10lf\n", 1.0 - ans);
}