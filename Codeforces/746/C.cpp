#include<bits/stdc++.h>
#define N
#define M
#define INF 0x3f3f3f3f
#define P pair<L,L>
#define L long long
#define MEM(n,i) memset(n,i,sizeof(n))
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D double
//#define int long long
//#define %d %lld
using namespace std;
int s,x1,x2,t1,t2,p,d,k,ans;
int main()
{
	scanf("%d%d%d%d%d%d%d",&s,&x1,&x2,&t1,&t2,&p,&d);
	ans=abs(x2-x1)*t2;
	if(d>0)
	{
		if(p<=x1&&x1<x2) k=x2-p;
		else
		if(x1<=p&&p<=x2) k=2*s-p+x2;
		else
		if(x1<x2&&x2<=p) k=2*s-p+x2;
		else
		if(p<=x2&&x2<x1) k=2*s-p-x2;
		else
		if(x2<=p&&p<=x1) k=2*s-p-x2;
		else
		if(x2<x1&&x1<=p) k=2*s-p-x2;
		ans=min(k*t1,ans);
	}
	else
	{
		if(p<=x1&&x1<x2) k=p+x2;
		else
		if(x1<=p&&p<=x2) k=p+x2;
		else
		if(x1<x2&&x2<=p) k=p+x2;
		else
		if(p<=x2&&x2<x1) k=2*s+p-x2;
		else
		if(x2<=p&&p<x1) k=2*s+p-x2;
		else
		if(x2<x1&&x1<=p) k=p-x2;
		ans=min(k*t1,ans);
	}
	printf("%d",ans);
	return 0;
}