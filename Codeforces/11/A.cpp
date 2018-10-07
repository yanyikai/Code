#include<bits/stdc++.h>
using namespace std;
int n,d,ans,a[2005];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int p=(a[i-1]-a[i]+d)/d;
		if(p>0)
		{
			a[i]+=p*d;
			ans+=p;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
4 2
1 3 3 2
*/