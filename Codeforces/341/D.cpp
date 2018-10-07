#include<cstdio>
#define int long long
using namespace std;
int a[2][2][1005][1005],n,m;
int Que(int l,int r)
{
	int res=0;
	for(int x=l;x;x-=x&-x)
		for(int y=r;y;y-=y&-y)
			res^=a[l&1][r&1][x][y];
	return res;
}
void Upd(int l,int r,int v)
{
	for(int x=l;x<=n;x+=x&-x)
		for(int y=r;y<=n;y+=y&-y)
			a[l&1][r&1][x][y]^=v;
}
main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=0,o,x0,x1,y0,y1,v;i<m;++i)
	{
		scanf("%lld%lld%lld%lld%lld",&o,&x0,&y0,&x1,&y1);
		if(o==1)
			printf("%lld\n",Que(x1,y1)^Que(x1,y0-1)^Que(x0-1,y1)^Que(x0-1,y0-1));
		else
			scanf("%lld",&v),Upd(x1+1,y1+1,v),Upd(x1+1,y0,v),Upd(x0,y1+1,v),Upd(x0,y0,v);
	}
	return 0;
}
