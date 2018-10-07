#include<cstdio>
#define N 200005
using namespace std;
int sum[N],a[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=2;i<=n;++i)
	{
		for(int j=1,t,v=i-2;j<=v;j=t+1)
		{
			t=v/(v/j);
			if(a[v/j+1]>a[i])++sum[j],--sum[t+1];
		}
		if(a[1]>a[i])++sum[i-1],--sum[n];
	}
	for(int i=1;i<n;++i)
		printf("%d ",sum[i]+=sum[i-1]);
	return 0;
}