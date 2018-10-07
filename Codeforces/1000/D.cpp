#include<cstdio>
using namespace std;
int n,f[1005][1005],x,p=998244353;
int main()
{
	scanf("%d",&n);**f=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		for(int j=0;j<=n;++j)
		{
			(f[i][j]+=f[i-1][j])%=p;
			if(j)(f[i][j-1]+=f[i-1][j])%=p;else
			if(x<n&&x>0)(f[i][x]+=f[i-1][j])%=p;
		}
	}
	printf("%d",(*f[n]+p-1)%p);
	return 0;
}
