#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,ans,a,b,t[105];
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	if(t[k]==1) ans++;
	t[0]=1;t[n+1]=1;a=k-1;b=k+1;
	while(a!=0||b!=n+1)
	{
		if(t[a]==1&&t[b]==1)
		{
			ans+=2;
			if(a==0||b==n+1) ans--;
		}
		if(a!=0) a--;
		if(b!=n+1) b++;
	} 
	printf("%d",ans);
	return 0;
}