#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n,m,sum=0,mxn=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	for(int i=0;i<n;++i)mxn=max(mxn,a[i]);
	for(int i=0;i<n;++i)sum+=mxn-a[i];
	printf("%d %d\n",sum>=m?mxn:(m-sum-1)/n+1+mxn,mxn+m);
	return 0;
}
