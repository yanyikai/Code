#include<cstdio>
#define N 1005
using namespace std;
char s[N],t[N];
int sum[N],n,m,q;
int check(int x)
{
	for(int i=0;i<m;++i)
		if(s[x+i]!=t[i+1])
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i)
		sum[i]=check(i)+sum[i-1];
	for(int l,r;q--;)
	{
		scanf("%d%d",&l,&r);
		r=r-m+1;
		if(r<l)puts("0");
		else printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}
