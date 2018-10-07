#include<set>
#include<cstdio>
#include<algorithm>
#define N 200005
#define P pair<int,int>
#define int long long
using namespace std;
int l[N],r[N],ans[N];
P b[N];set<P>s;
struct T{
	int l,r,id;
	T(){}
	T(int a,int b,int c):l(a),r(b),id(c){}
	bool operator<(const T&o)const{
		return l<o.l;
	}
}a[N];
main()
{
	int n,m;scanf("%lld%lld",&n,&m);
	if(m<n-1)return puts("No"),0;
	for(int i=0;i<n;++i)
		scanf("%lld%lld",l+i,r+i);
	for(int i=1;i<n;++i)
		a[i]=T{l[i]-r[i-1],r[i]-l[i-1],i};
	for(int i=0;i<m;++i)
		scanf("%lld",&b[i].first),b[i].second=i+1;
	sort(b,b+m);sort(a+1,a+n);int k=1;
	for(int i=0;i<m;++i)
	{
		for(;k<n&&a[k].l<=b[i].first;++k)
			s.insert(P(a[k].r,a[k].id));
		if(s.empty())continue;
		if(s.begin()->first<b[i].first)return puts("No"),0;
		ans[s.begin()->second]=b[i].second;s.erase(s.begin());
	}
	// for(int i=1;i<=cnt;++i)printf("%lld\n",ans[i]);
	if(k!=n||!s.empty())return puts("No"),0;
	puts("Yes");
	for(int i=1;i<n;++i)
		printf("%lld ",ans[i]);
	return 0;
}