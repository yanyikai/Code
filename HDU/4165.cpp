#include<cstdio>
#define N 65
using namespace std;
unsigned long long C[N][N];
int main()
{
	**C=1;
	for(int i=1;i<N;++i)
		for(int j=0;j<=i;++j)
			C[i][j]=j?C[i-1][j-1]+C[i-1][j]:1;
	for(int n;~scanf("%d",&n)&&n;)
		printf("%llu\n",C[2*n][n]-C[2*n][n-1]);
	return 0;
}
