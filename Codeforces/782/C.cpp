#include<queue>
#include<cstdio>
#include<iostream>
#define N 200010
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int rud[N],fir[N],col[N],arr[N<<1],nex[N<<1],ans;
struct P{int x,y,z;};queue<P>Q;
int main()
{
	int n=read();
	for(int i=1,e=0;i<n;++i)
	{
		int u=read(),v=read();
		arr[++e]=u;nex[e]=fir[v];fir[v]=e;
		arr[++e]=v;nex[e]=fir[u];fir[u]=e;
		++rud[u];++rud[v];
	}
	for(int i=1;i<=n;++i)
		ans=max(ans,rud[i]);
	printf("%d\n",ans+1);
	Q.push((P){1,1,0});col[1]=1;
	for(;!Q.empty();)
	{
		P t=Q.front();Q.pop();
		for(int i=fir[t.x],j=1;i;i=nex[i])
			if(!col[arr[i]])
			{
				for(;j==t.y||j==t.z;++j);
				col[arr[i]]=j;
				Q.push((P){arr[i],col[arr[i]],t.y});
				++j;
			}
	}for(int i=1;i<=n;++i)printf("%d ",col[i]);
	return 0;
}