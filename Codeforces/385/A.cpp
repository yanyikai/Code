#include<bits/stdc++.h>
using namespace std;
int n,k,i,x,y,ans;
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&y);
		if(x>=y)
		{
			ans=max(ans,x-y-k);
		}
		x=y;
	}
	printf("%d",ans);
	return 0;
}