#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,x,i,ans,a[1000000],cut,maxn,minn,sum;
bool cmp(int x,int y){ return x>y; }
int main()
{
	maxn=-inf;
	minn=inf;
	for(scanf("%d",&n),i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x>0) sum+=x;
		if(x&1&&x<0&&x>maxn) maxn=x;
		if(x&1&&x>0&&x<minn) minn=x;
	}
	sum&1?printf("%d",sum):printf("%d",max(sum-minn,sum+maxn));
	return 0;
}