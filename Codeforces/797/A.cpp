#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a[100],cut=0,i,ans=1;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);	
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				a[++a[0]]=i;
				n/=i;
			}
		}
	}
	if(a[0]<k) printf("-1");
	else
	{
		for(i=1;i<k;i++)
		{
			printf("%d ",a[i]);
		}
		for(;i<=a[0];i++)
		{
			ans*=a[i];
		}
		printf("%d",ans);
	}
	return 0;
}