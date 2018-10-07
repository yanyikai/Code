#include<bits/stdc++.h>
#define maxn 10000005
using namespace std;
int t[10000007],n,i,j,x,y,ans,m,sum[10000007];
bool p[10000007];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		t[x]++;
	}
	for(i=2;i<=maxn;i++)
	{
		if(!p[i])
		{
			sum[i]=t[i];
			for(j=i+i;j<=maxn;j+=i)
			{
				p[j]=true;
				if(t[j]) sum[i]+=t[j];
			}
		}
	}
	for(i=1;i<=maxn;i++)
	{
		sum[i]+=sum[i-1];
//		printf("%d ",sum[i]);
	}
//	printf("\n");
	scanf("%d",&m);
	while(m--)
	{
		ans=0;
		scanf("%d%d",&x,&y);
		if(x!=maxn) x=min(x,maxn-1);y=min(y,maxn);
		ans=sum[y]-sum[x-1];
		printf("%d\n",ans);
	}
	return 0;
}