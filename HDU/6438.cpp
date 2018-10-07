#include<cstdio>
#include<queue>
#define int long long
#define P pair<int,int>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
signed main()
{
	for(int cas=0,T=read();cas<T;++cas)
	{
		priority_queue<P,vector<P>,greater<P> >Q;
		int n=read(),num=0,ans=0;
		for(int i=0;i<n;++i)
		{
			int x=read();
			if(!Q.empty()&&Q.top().first<x)
			{
				P t=Q.top();Q.pop();
				++num;ans+=x-t.first;
				t.second?++num:--num;
				Q.push(P(x,0));
			}Q.push(P(x,1));
		}
		printf("%lld %lld\n",ans,num);
	}
	return 0;
}
