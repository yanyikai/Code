#include<cstdio>
using namespace std;
#define N 4200000
inline char gc(){
    static char buf[1<<16],*S,*T;
    if(S==T){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=0;register char ch=gc();
    for(;ch<48||ch>57;ch=gc())f|=ch=='-';
    for(;ch>47&&ch<58;ch=gc())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
int n,m,ans,a[N],fat[N];bool vis[N],f[N];
inline int Fin(int x){return x==fat[x]?x:fat[x]=Fin(fat[x]);}
inline void merge(int x,int y){
	int xx=Fin(x),yy=Fin(y);
	if(xx!=yy)fat[xx]=yy;
}
void dfs(int x,int y){
    if(!f[x]) return;
    if(Fin(x)==Fin(y)) return;
    merge(x,y);
    for(int i=0;i<n;++i)
        if(x&(1<<i))dfs(x^(1<<i),y);
}
int main(){
    n=read();m=read();
    for(int i=1;i<=m;++i)a[i]=read(),f[a[i]]=1;
    for(int i=0;i<1<<n;++i){
        fat[i]=i;
        for(int j=0;j<n;++j)
            if(i&(1<<j))f[i]|=f[i^(1<<j)];
    }
    for(int i=1;i<=m;++i) dfs((1<<n)-1^a[i],a[i]);
    for(int i=1;i<=m;++i) ans+=Fin(a[i])==a[i];
    printf("%d\n",ans);
    return 0;
}
