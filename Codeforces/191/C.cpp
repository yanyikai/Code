#include <cstdio>
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
int fir[N],nex[N<<2],arr[N<<2],e,hea[N],fat[N],num[N],ans[N];
int find(int x){return x==fat[x]?x:fat[x]=find(fat[x]);}
void dfs(int x)
{
	fat[x]=x;
	for(int i=hea[x];i;i=nex[i])
	{
		++num[x];
		if(fat[arr[i]])
			num[find(arr[i])]-=2;
	}
	for(int i=fir[x];i;i=nex[i])
	if(!fat[arr[i]])
	{
		dfs(arr[i]);
		num[x]+=ans[i+1>>1]=num[arr[i]];
		fat[arr[i]] = x;
	}
}
int main(){
	int n=read();
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read();
		arr[++e]=y;nex[e]=fir[x];fir[x]=e;
		arr[++e]=x;nex[e]=fir[y];fir[y]=e;
	}
	int m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		if(x==y)continue;
		arr[++e]=y;nex[e]=hea[x];hea[x]=e;
		arr[++e]=x;nex[e]=hea[y];hea[y]=e;
	}dfs(1);
	for(int i=1;i<n;++i)
		printf("%d ",ans[i]);
	return 0;
}