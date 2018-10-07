#include<cstdio>
#define int long long
using namespace std;
int a[100005],n,m,ans;
int check(int t)
{
	int cnt=m,s=0;
	for(int i=1;i<=n;++i)
		for(s+=a[i];s+i>=t;)
		{
			s-=t-i;
			if(--cnt<0)return 0;
		}
	return cnt?1:s<=0;
}
main()
{
	scanf("%lld%lld",&n,&m);
	int l=0,r=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		r+=a[i];if(a[i])l=i;
	}r+=l;n=l;
	for(;l<=r;)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}