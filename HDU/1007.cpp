#include<cmath>
#include<cstdio>
#include<algorithm>
#define N 200005
using namespace std;
struct P{
	double x,y;
	void in(){scanf("%lf%lf",&x,&y);}
	bool operator<(const P&o)const{
		return x==o.x?y<o.y:x<o.x;
	}
}a[N];int tmp[N];double ans=2e9;
double sqr(double x){return x*x;}
double dis(P a,P b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double merge(int l,int r)
{
	double d=2e9;
	if(l==r)return 2e9;
	if(l+1==r)return dis(a[l],a[r]);
	int mid=(l+r)>>1,cnt=0;
	d=min(merge(l,mid),merge(mid+1,r));
	for(int i=l;i<=r;++i)
		if(fabs(a[i].x-a[mid].x)<=d)
			tmp[++cnt]=i;
	sort(tmp+1,tmp+cnt+1,[](int x,int y)->bool{return a[x].y<a[y].y;});
	for(int i=1;i<cnt;++i)
		for(int j=i+1;j<=cnt&&a[tmp[j]].y-a[tmp[i]].y<d;++j)
			d=min(d,dis(a[tmp[i]],a[tmp[j]]));
	return d;
}
int main()
{
	for(int n;~scanf("%d",&n)&&n;)
	{
		for(int i=0;i<n;++i)a[i].in();
		sort(a,a+n);
		printf("%.2lf\n",merge(0,n-1)/2);
	}
	return 0;
}
