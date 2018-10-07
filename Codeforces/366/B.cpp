#include<bits/stdc++.h>
#define N 100005
#define P pair<L,L>
#define L long long
#define INF 0x3f3f3f3f
using namespace std;
int t[N],n,k,pos,minn=INF,x;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n/k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			t[j]+=x;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(t[i]<minn)
		{
			minn=t[i];
			pos=i;
		}
	}
	printf("%d",pos);
	return 0;
}