#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans,p,i;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if((x-1)/m>=ans) ans=(x-1)/m,p=i;
	}
	printf("%d",p);
	return 0;
}