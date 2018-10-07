#include<cstdio>
#define N 2005
using namespace std;
long long C[N][N],S[N][N],p=1e9+7;
int main()
{
	**C=**S=1;
	for(int i=1;i<N;++i)
		for(int j=0;j<=i;++j)
		{
			C[i][j]=j?(C[i-1][j-1]+C[i-1][j])%p:1;
			S[i][j]=j?(S[i-1][j]*(i-1)+S[i-1][j-1])%p:0;
		}
	int T;scanf("%d",&T);
	for(int n,f,b;T--;)
	{
		scanf("%d%d%d",&n,&f,&b);
		if(f+b>n+2)puts("0");
		else printf("%lld\n",C[f+b-2][f-1]*S[n-1][f+b-2]%p);
	}
	return 0;
}
