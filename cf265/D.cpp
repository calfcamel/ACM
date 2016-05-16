#include <stdio.h>
#define FOR(i,x) for(int i = 0,__END__ = (int)(x); i < __END__;i++)
#define FORR(i,x) for(int i = 1,__END__ = (int)(x); i <= __END__;i++)
#define FORR(i,y,x) for(int i = (int)(y),__END__ = (int)(x); i <= __END__;i++)

struct point
{
	int x,y,z;
	point(){}
	point(int xx,int yy,int zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	point &operator+(point& A)
	{
		x = x + A.x;
		y = y + A.y;
		z = z + A.z;
		return *this;
	} 
	point &operator-(point& A)
	{
		x = x - A.x;
		y = y - A.y;
		z = z - A.z;
		return *this;
	} 
}a[8];

int vis[8];

int main()
{
	for(int i = 0; i < 8; i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	point c = a[0] + a[1];
	printf("%d %d %d\n",c.x,c.y,c.z);
}