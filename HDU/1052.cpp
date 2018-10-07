#include<bits/stdc++.h>
using namespace std;
int n,i,j,ans,res,a[2005],b[2005];
int main()
{
	for(;~scanf("%d",&n)&&n;printf("%d\n",ans*200))
	{
		ans=-1e5;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		for(i=1;i<=n;i++) a[i+n]=a[i];
		for(i=1;i<=n;i++) b[i+n]=b[i];
		for(i=1;i<=n;i++)
		{
			res=0;
			for(j=i;j<=n+i-1;j++)
			{
				if(a[j]>b[j-i+1]) res++;
				if(a[j]<b[j-i+1]) res--;
			}
			ans=max(ans,res);
		}
	}
	return 0;
}
