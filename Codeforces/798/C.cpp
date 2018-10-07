#include<bits/stdc++.h>
using namespace std;
int i,n,g,ans,t[100007];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t[i]);
		g=__gcd(g,t[i]);
		t[i]%=2;
	}
	printf("YES\n");
	if(g>1)
	{
		printf("0");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(t[i])
		{
			if(t[i+1]) ans++;
			else ans+=2;
			i++;
		}
	}
	printf("%d",ans);
	return 0;
}