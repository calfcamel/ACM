#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = (1 << 7) + 5;


typedef double MatType;
const int MatN = 2;
struct Mat
{
    int n;
    MatType m[MatN][MatN];
    Mat(int n = MatN,MatType I = 0)
    {
        Init(n,I);
    }
    /*
    Mat(const Mat& M)
    {
        n = M.n;
        memcpy(m,M.m,sizeof m);
    }
    Mat& operator=(const Mat& M)
    {
        n = M.n;
        memcpy(m,M.m,sizeof m);
        return *this;
    }*/
    void Init(int _n,MatType _I)
    {
        n = _n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i == j) m[i][j] = _I;
                else m[i][j] = 0;
    }
    Mat& operator+(const Mat& M)
    {
        Mat ret(M.n,0);
        for(int i = 0; i < M.n; i++)
            for(int j = 0; j < M.n; j++)
                ret.m[i][j] = M.m[i][j] + m[i][j];
        return ret;
    }
    Mat& operator*(const Mat& M)
    {
        Mat ret(M.n,0);
        for(int i = 0; i < M.n; i++)
            for(int j = 0; j < M.n; j++)
                for(int k = 0; k < M.n; k++)
                    //if(m[i][k] && M.m[k][j])
                        ret.m[i][j] += m[i][k] * M.m[k][j];
        //cout <<"MUL:" <<endl;
        //cout << "n = " << ret.n <<endl;
        for(int i = 0; i < ret.n; i++)
        {
            for(int j = 0; j < ret.n; j++)
                ret.m[i][j] + 0.0;
                //cout << ret.m[i][j] << " ";
            //cout << endl;
        }
        return ret;
    }
    Mat& operator^(int x)
    {
        if(x < 0)
        {
            Mat B(n, 0);
            return B;
        }
        if(x == 0)
        {
            Mat B(n,1);
            return B;
        }
        Mat A;
        A.n = n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                A.m[i][j] = m[i][j];
        Mat ret(n,1);
        while(x)
        {
            if(x & 1) ret = ret * A;
            A = A * A;
            x >>= 1;
        }
        return ret;
    }
};

void displayMat(const Mat & A,string s)
{
    cout << "=====================" << endl;
    cout << s << endl;
    cout << "n = " << A.n <<endl;
    for(int i = 0; i < A.n; i++)
    {
        for(int j = 0; j < A.n; j++)
            cout << A.m[i][j] << " ";
        cout << endl;
    }
    cout << "=====================" << endl;
}
const double eps = 1e-9;
int a[20];
int main()
{
    int n;
    double p;
    while(scanf("%d%lf",&n,&p)!= EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        a[n] = 0;
        sort(a,a+n + 1);
        if(a[1] == 1)
        {
            printf("%.7f\n",0.0);
            continue;
        }
        else
        {
            Mat A(2,0);
            Mat B(2,0);
            B.m[0][0] = p;
            B.m[0][1] = 1.0;
            B.m[1][0] = 1.0 - p;
            B.m[1][1] = 0.0;

            A.m[0][0] = 1.0;
            A.m[0][1] = 1.0;
            A.m[1][0] = 0.0;
            A.m[1][1] = 0.0;
            Mat C(2,0);
            C.m[0][0] = 1.0 - p;
            C.m[0][1] = 0.0;
            C.m[1][0] = 0.0;
            C.m[1][1] = 0.0;
            Mat B2 = A * B;
            B2 = B2 * B;
            //displayMat(B2,"INIT _B");
            for(int i = 1; i <= n; i++)
            {
                //displayMat(A,"before");
                //cout << " * " << a[i] - a[i - 1]  - 2<< endl;
                Mat x = B ^ (a[i] - a[i - 1] - 1);
                //displayMat(x,"B");
                A = A * x;
                //displayMat(A,"after");
                A = A * C;
                //displayMat(A,"after * C");
            }
            //A = A * B;
            printf("%.7f\n",A.m[0][0] + eps);
        }
    }
}
