#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ii pair<int,int>
#define N 100005
using namespace std;
int n,l[N],c[N],j,i,len,ans,sum,tot;
ii ls[N],cs[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&l[i]);
	for(i=1;i<=n;i++) scanf("%d",&c[i]),sum+=c[i];
	for(i=1;i<=n;i++) ls[i]=ii(l[i],c[i]),cs[i]=ii(c[i],l[i]);
	sort(ls+1,ls+n+1);sort(cs+1,cs+n+1);
	for(i=1;i<=n;i++)
	{
		tot+=ls[i].second;len++;
		if(ls[i].first!=ls[i+1].first)
		{
			j=n;
			while(j&&len>1)
			{
				if(cs[j].second<ls[i].first) tot+=cs[j].first,len--;  
				j--;
			}
			ans=max(ans,tot);
			tot=len=0;
		}
	}
	printf("%d",sum-ans);
	return 0;
}