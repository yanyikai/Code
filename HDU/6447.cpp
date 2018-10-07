#pragma GCC diagnostic error "-std=c++11"
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define N 100005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
struct P{
	int x,y,v;
	bool operator<(const P&o)const{
		return x<o.x;
	}
	void in(){x=read(),y=read(),v=read();}
}a[N];
int tmp[N],n,m,tot,c[N],f[N];
vector<int>x[N];
inline int Que(int p){
	int res=0;
	for(;p;p-=p&-p)res=max(res,c[p]);
	return res;
}
inline void Upd(int p,int v){
	for(;p<=m;p+=p&-p)c[p]=max(c[p],v);
}
int main()
{
	for(int cas=0,T=read();cas<T;++cas)
	{
		n=read(),m=n;a[0].x=-1;tot=0;
		for(int i=1;i<=n;++i)a[i].in(),tmp[i]=a[i].y;
		sort(tmp+1,tmp+m+1);
		m=unique(tmp+1,tmp+m+1)-tmp-1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
		{
			a[i].y=lower_bound(tmp+1,tmp+m+1,a[i].y)-tmp;
			if(a[i].x>a[i-1].x)
				x[++tot].clear();
			x[tot].push_back(i);
		}
		int ans=0;
		memset(c,0,sizeof c);
		for(int i=1;i<=tot;++i)
		{
			for(int v:x[i])
				f[v]=Que(a[v].y-1)+a[v].v,
				ans=max(ans,f[v]);
			for(int v:x[i])Upd(a[v].y,f[v]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
