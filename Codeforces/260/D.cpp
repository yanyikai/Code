#include<cstdio>
#include<algorithm>
#define N 100005
#define P pair<int,int>
using namespace std;
P a[2][N];int l[2];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1,c,v;i<=n;++i)
	{
		scanf("%d%d",&c,&v);
		a[c][++l[c]]=P(v,i);
	}
	sort(a[0]+1,a[0]+l[0]+1);
	sort(a[1]+1,a[1]+l[1]+1);
	int i0=1,i1=1;
	for(;i0<=l[0]&&i1<=l[1];)
	{
		int del=min(a[0][i0].first,a[1][i1].first);
		a[0][i0].first-=del;a[1][i1].first-=del;
		printf("%d %d %d\n",a[0][i0].second,a[1][i1].second,del);
		if(a[0][i0].first+a[1][i1].first==0)i0<l[0]?++i0:++i1;else
		{
			if(!a[0][i0].first)++i0;
			if(!a[1][i1].first)++i1;
		}
	}
	return 0;
}