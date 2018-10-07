#include<bits/stdc++.h>
using namespace std;
int n,p,a[100005],res[100005],ans[100005],sum;
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		res[i]=(res[i-1]+a[i])%p;
	}
	for(int i=n;i;--i)
		ans[i]=(ans[i+1]+a[i])%p;
	for(int i=1;i<n;++i)
		sum=max(sum,res[i]+ans[i+1]);
	printf("%d",sum);
	return 0;
}
