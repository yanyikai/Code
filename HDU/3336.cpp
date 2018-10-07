#include<cstdio>
using namespace std;
long long T,ans,l,i,j,p[200005];
char s[200005];
int main()
{
	scanf("%lld",&T);
	p[0]=-1;
	while(T--)
	{
		ans=0;
		scanf("%lld\n",&l);
		for(i=1;i<=l;i++) scanf("%c",&s[i]);
		for(i=1,j=-1;i<=l;i++)
		{
			while(j>=0&&s[j+1]!=s[i]) j=p[j];
			p[i]=++j;
		}
		for(i=1;i<=l;i++) if(p[i]>0) ans++;
		ans=(ans+l)%10007;
		printf("%lld\n",ans);
	}
	return 0;
}
