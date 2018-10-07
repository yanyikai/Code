#include<cstdio>
#include<algorithm>
#define N 1000005
#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int n,seed,x[N],y[N];
inline int rand(int l,int r){
	static int mo=1e9+7,g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}
inline void mxn(int&p,int q){p<q?p=q:0;}
inline void mnn(int&p,int q){p>q?p=q:0;}
signed main()
{
	for(int cas=0,T=read();cas<T;++cas)
	{
		n=read(),seed=read();
		for(int i=0;i<n;++i)
			x[i]=rand(-1e9,1e9),
			y[i]=rand(-1e9,1e9);
		int a=*x+*y,b=*x+*y,c=*x-*y,d=*x-*y;
		for(int i=1;i<n;++i)
			mxn(a,x[i]+y[i]),
			mnn(b,x[i]+y[i]),
			mxn(c,x[i]-y[i]),
			mnn(d,x[i]-y[i]);
		printf("%lld\n",max(abs(a-b),abs(c-d)));
	}
	return 0;
}
