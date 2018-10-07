#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,l,tot,ans,f;
char s[10000];
struct P
{
	int a,b;
}m[1000];
int cmp(P x,P y){return x.a>y.a;}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%s",s);
		l=strlen(s);
		for(int j=0;j<l;++j)
		{
			if(!j)m[s[j]].b=1;
			m[s[j]].a+=pow(10,l-j-1);
		}
	}
	sort(m,m+200,cmp);
	for(i=0;i<=200;++i)
	{
		if(!f&&!m[i].b)
			f=1;
		else
			ans+=(++tot)*m[i].a;
	}
	printf("%d",ans);
	return 0;
}
