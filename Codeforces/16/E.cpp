#include<cstdio>
#define F(i,n) for(int i=0;i<n;++i)
#define B(i) __builtin_popcount(i)
double a[18][18],dp[1<<18]={1.0};
int main()
{
	int n;
	scanf("%d",&n);
	F(i,n) F(j,n) scanf("%lf",&a[i][j]);
	F(k,1<<n) F(i,n) if(!(k&(1<<i)))
	F(j,n) if(!(k&(1<<j))) if(i!=j) dp[k|(1<<j)]+=dp[k]*a[i][j]/(n-B(k))/(n-B(k)-1)*2;
	F(i,n) printf("%lf ",dp[((1<<n)-1)^(1<<i)]);
	return 0;
}