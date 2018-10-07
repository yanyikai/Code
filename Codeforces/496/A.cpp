#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,x,t[1001],minn=99999999,maxn;
int main()
{
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		t[i]=x-k;
		k=x;
	}
	if(n==3)
	{
		printf("%d",t[1]+t[2]);
		return 0;
	}
	for(i=1;i<n-1;i++)
	{
		minn=min(minn,t[i]+t[i+1]);
	}
	for(i=1;i<n;i++)
	{
		maxn=max(maxn,t[i]);
	}
	maxn=max(maxn,minn);
	printf("%d",maxn);
	return 0;
}