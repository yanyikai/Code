#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[5005],t[5005],ans;
double k;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%lf",&a[i],&k);
	}
	for(i=1;i<=n;i++) t[i]=1;
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>=1;j--)
		{
			if(a[j]<=a[i]) t[i]=max(t[i],t[j]+1);
		}
	}
	for(i=1;i<=n;i++) ans=max(ans,t[i]);
	printf("%d",n-ans);
	return 0;
}