#include<cstdio>
#include<iostream>
#define N 200005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int arr[N<<1],nex[N<<1],fir[N],dep[N]={-1},fat[N],maxn[N];
void dfs(int x)
{
	maxn[x]=dep[x]=dep[fat[x]]+1;
	for(int i=fir[x];i;i=nex[i])
	{
		if(arr[i]!=fat[x])
		{
			fat[arr[i]]=x;dfs(arr[i]);
			maxn[x]=max(maxn[x],maxn[arr[i]]);
		}
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=1,e=0;i<n;++i)
	{
		int x=read(),y=read();
		arr[++e]=x;nex[e]=fir[y];fir[y]=e;
		arr[++e]=y;nex[e]=fir[x];fir[x]=e;
	}dfs(1);
	int ans=maxn[m]*2;
    for(int i=0,k=m;i<dep[m];i++,k=fat[k])
    {
        if(i<dep[k])
        {
            ans=max(ans,maxn[k]*2);
        }
        else
        break;
    }
    cout<<ans<<endl;
	return 0;
}