#include <stdio.h>
#include <math.h>

double sqr(double x)
{
	return x * x;
}
double cal()
{
	double ox,oy,ax,ay,bx,by;
	scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
	double R = sqrt(sqr(ax - ox) + sqr(ay - oy));
	double L = sqrt(sqr(ax - bx) + sqr(ay - by)) / 2.0;
	double s = 2 * asin(L / R);
	return R * s;
}
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		printf("Case %d: %.10f\n", CAS, cal());
	}
}
/*
给圆心O跟圆上2个点AB，求最短的弧AB的距离
5
5711 3044 477 2186 3257 7746
3233 31 3336 1489 1775 134
453 4480 1137 6678 2395 5716
8757 2995 4807 8660 2294 5429
4439 4272 1366 8741 6820 9145

*/