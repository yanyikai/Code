#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;
int a[N];
int get(int l,int r)//[l,r]
{
	int mxn=2e9;
	for(int i=l;i<=r;++i)
		mxn=min(mxn,a[i]);
	for(int i=l;i<=r;++i)
		a[i]-=mxn;
	int res=mxn;
	for(int i=l;i<=r;++i)
		if(a[i])
		{
			int _r=i+1;
			for(;a[_r]&&_r<=r;++_r);
			res+=get(i,_r-1);i=_r;
		}
	// printf("%d %d %d %d\n",l,r,res,r-l+1);
	return min(res,r-l+1);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	printf("%d\n",get(1,n));
	return 0;
}