#include<cstdio>
using namespace std;
int n;
void put(int t)
{
	for(int i=2;i<=n;++i)
		printf("%d %d\n",1+t,i+t);
	for(int i=2;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(i+j!=n+2)
				printf("%d %d\n",i+t,j+t);
	for(int i=2;i<=n;++i)
	{
		printf("%d %d\n",i+t,n+1+t);
		printf("%d %d\n",i+t,n+2+t);
	}
	printf("%d %d\n",n+1+t,n+2+t);
}
int main()
{
	scanf("%d",&n);
	if(!(n&1))return puts("NO"),0;puts("YES");
	if(n==1)return puts("2 1\n1 2"),0;
	printf("%d %d\n%d %d\n",2*(n+2),n*(n+2),1,n+3);
	put(0);put(n+2);
	return 0;
}