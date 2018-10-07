#include<bits/stdc++.h>
using namespace std;
struct P{
	int l,r,id;
}a[300005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		a[i].l=l;
		a[i].r=r;
		a[i].id=i+1;
	}
	sort(a,a+n,[](const P&x,const P&y)->bool{return x.l==y.l?x.r<y.r:x.l<y.l;});
	int mr=a[0].r,p=0;
	for(int i=1;i<n;++i)
	{
		if(a[i].l==a[i-1].l)
			return printf("%d %d\n",a[i-1].id,a[i].id),0;
		if(a[i].r<=mr)
			return printf("%d %d\n",a[i].id,a[p].id),0;
		mr=a[i].r;p=i;
	}
	puts("-1 -1");
	return 0;
}
