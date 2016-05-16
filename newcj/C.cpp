#include <stdio.h>
#include <math.h>


	double ans;
	double sum;
	int n;
	double ax,ay,bx,by,tx,ty;
double x[100005];
double y[100005];
double dis[100005];
double disa[100005];
double disb[100005];
inline double sqr(double x)
{
	return x * x;
}
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(int i = 0; i < n; i++)
		dis[i] = sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
	for(int i = 0; i < n; i++)
		disa[i] = sqrt(sqr(x[i] - ax) + sqr(y[i] - ay)) - dis[i];
	for(int i = 0; i < n; i++)
		disb[i] = sqrt(sqr(x[i] - bx) + sqr(y[i] - by)) - dis[i];
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += dis[i] + dis[i];
	int sai = 0;
	double sa = disa[0];
	for(int i = 1; i < n; i++)
		if(sa > disa[i])
		{
			sai = i;
			sa = disa[i];
		}
	ans = sum + sa;
	int sbi = 0;
	double sb = disb[0];
	for(int i = 1; i < n; i++)
		if(sb > disb[i])
		{
			sbi = i;
			sb = disb[i];
		}
	if(ans > sum + sb)
	{
		ans = sum + sb;
	}
	if(n == 1)
	{
		printf("%.10lf\n", ans);
		return 0;
	}
	double tmp;
	tmp = disb[0];
	if(sai == 0)
		tmp = disb[1];
	for(int i = 1; i < n; i++) if(i != sai)
		if(tmp > disb[i])
			tmp = disb[i];
	if(ans > sum + sa + tmp)
		ans = sum + sa + tmp;
	tmp = disa[0];
	if(sbi == 0)
		tmp = disa[1];
	for(int i = 1; i < n; i++) if(i != sbi)
		if(tmp > disa[i])
			tmp = disa[i];
	if(ans > sum + sb + tmp)
		ans = sum + sb + tmp;
	printf("%.10lf\n", ans);
	return 0;
}