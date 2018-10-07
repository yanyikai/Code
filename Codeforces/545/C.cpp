#include<bits/stdc++.h>
#define inf 0x7f7f7f7f;
using namespace std;
struct tree
{
	long long x,h;
}tr[100001];
long long n,i,ans;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&tr[i].x,&tr[i].h);
	}
	tr[0].x=-inf;
	tr[n+1].x=inf;
	for(i=1;i<=n;i++)
	{
		if(tr[i].x-tr[i-1].x>tr[i].h) ans++;
		else
		{
			if(tr[i+1].x-tr[i].x>tr[i].h)
			{
				ans++;
				tr[i].x+=tr[i].h;
			}
		}
	}
	printf("%d",ans);
	return 0;
}