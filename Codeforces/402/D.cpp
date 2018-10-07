#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 5005
#define M 35000
using namespace std;
int a[N],b[N],c[N],n,m,ans;
bool vis[M];
int p[4000],tot;
int check(int x)
{
	int sum=0;
	for(int i=1;i<=m&&x>=c[i];++i)
		for(;!(x%c[i]);x/=c[i])--sum;
	for(int i=1;i<=tot&&x>=p[i];++i)
		for(;!(x%p[i]);x/=p[i])++sum;
	if(x!=1)++sum;
	return sum;
}
int main()
{
	for(int i=2;i<M;++i)
		if(!vis[i])
		{
			p[++tot]=i;
			for(int j=i+i;j<M;j+=i)
				vis[j]=1;
		}
	// printf("%d\n",tot);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=m;++i)
		scanf("%d",c+i);
	for(int i=1;i<=n;++i)
		ans+=check(a[i]);
	// printf("%d\n",ans);
	b[1]=a[1];
	for(int i=2;i<=n;++i)
		b[i]=__gcd(b[i-1],a[i]);
	for(int i=n;i;--i)
	{
		if(b[i]==1)continue;
		int t=check(b[i]);
		if(t<0)
		{
			ans-=t*i;
			for(int j=1;j<i;++j)
				b[j]/=b[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}