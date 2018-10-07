#include<bits/stdc++.h>
using namespace std;
#define N 50
long long n,k,M,ans,tot,now,ans_,d,i,j,e;
int t[N+5];
int main()
{
	for(scanf("%d%d%d",&n,&k,&M),i=0; i<k; i++) scanf("%d",&t[i]),tot+=t[i];
	sort(t,t+k);
	for(e=0;e<=n;e++)
	{
		now=tot*e;
		if(now>M) break;
		ans_ = (k+1)*e;
		for(i=0;i<k;i++)
		{
			for(j=e+1;j<=n;j++)
			{
				now+=t[i];
				ans_++;
				if(now>M)
				{
					ans_--;
					i=k+1;
					break;
				}
			}
		}
		ans=max(ans,ans_);
	}
	printf("%d",ans);
	return 0;
}