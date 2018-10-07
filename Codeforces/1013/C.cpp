#include<bits/stdc++.h>
#define N 200005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int a[N];
long long ans=2e18;
map<int,int>m;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n*2;++i)
		scanf("%d",a+i),++m[a[i]];
	for(auto v:m)if(v.second>=n)return puts("0"),0;
	sort(a+1,a+n*2+1);
	for(int i=n+1;i<n*2;++i)
		ans=min(ans,1ll*(a[n*2]-a[1])*(a[i]-a[i-n+1]));
	ans=min(ans,1ll*(a[n]-a[1])*(a[2*n]-a[n+1]));
	printf("%lld\n",ans);
	return 0;
}
