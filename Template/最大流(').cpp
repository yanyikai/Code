#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#define R register
const int N=1e6+5,M=8e6+7,inf=0x7f7f7f7f;
int n,m,s,t,a,b,c,e=1,ans,fir[N],dep[N],arr[M],nex[M],val[M],cur[N],Q[N],*be,*en;
//fastIO
const int MAX_SIZE=1<<15;char *l,*r;char buf[MAX_SIZE];
inline int gc(){if(l==r)if(l==(r=(l=buf)+fread(buf,1,MAX_SIZE,stdin)))return -1;return *l++;}
inline void read(int &x){R char c=gc();for(;c<48||c>57;c=gc());
for(x=0;c>47&&c<58;c=gc())x=(x<<3)+(x<<1)+(c^48);}
inline int bfs()
{
    memset(dep,0,(n<<2)+16);
    for((*(be=en=Q+1)=s)[dep]=1;!(en<be);++be)
        for(R int i=fir[*be];i;i=nex[i])
        	if(val[i]&&!i[arr][dep])
                (*(++en)=arr[i])[dep]=dep[*be]+1;
    return dep[t];
}
int dfs(int x,int maxn)
{
	if(x==t||!maxn)return maxn;int res=0,tmp;
	for(int&i=cur[x];i;i=nex[i])
		if(val[i]&&i[arr][dep]==dep[x]+1&&(tmp=dfs(arr[i],maxn>val[i]?val[i]:maxn)))
		{
			res+=tmp;val[i]-=tmp;val[i^1]+=tmp;maxn-=tmp;
			if(!maxn)return res;
		}
    if(!res)dep[x]=0;
    return res;
}
void ADD(int u,int v,int w){
    arr[++e]=b,val[e]=w,nex[e]=fir[a];fir[a]=e;
}
signed main()
{
    read(n);read(m);read(s);read(t);
    for(R int i=0;i<m;++i)
    {
        read(a);read(b);read(c);
        ADD(a,b,c);ADD(b,a,c);
    }
    for(;bfs();ans+=dfs(s,inf))
        memcpy(cur+1,fir+1,(n<<2)+16);
    printf("%d",ans);
    return 0;
}