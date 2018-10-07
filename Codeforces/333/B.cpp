#include<bits/stdc++.h>
#define N 1000
using namespace std;
int n,i,x,y,ans,k;
bool X[N+5],Y[N+5];
int main()
{
	memset(X,true,sizeof(X));
	memset(Y,true,sizeof(Y));
	for(scanf("%d%d",&n,&k),i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		X[x]=false;
		Y[y]=false;
	}
	for(i=2;i<n;i++)
	{
		if(X[i]) ans++;
		if(Y[i]) ans++;
	}
	if(n&1&&X[(n+1)>>1]&&Y[(n+1)>>1]) ans--;
	printf("%d",ans);
	return 0;
}