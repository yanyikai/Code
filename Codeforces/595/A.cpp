#include<bits/stdc++.h>
using namespace std;
int x,y,i,j,ans,n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d%d",&x,&y);
			if(x==1||y==1) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}