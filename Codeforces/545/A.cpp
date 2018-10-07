#include<bits/stdc++.h>
using namespace std;
int i,j,x,n,ans;
bool a[101];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if(x==3)
			{
				a[i]=true;
				a[j]=true;
			}
			else
			{
				if(x==1) a[i]=true;
				if(x==2) a[j]=true;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!a[i]) ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
	{
		if(!a[i]) printf("%d ",i);
	}
	return 0;
}