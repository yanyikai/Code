#include<bits/stdc++.h>
using namespace std;int fat[100],p=0;
template<typename Tp=long long>inline Tp Pow(Tp x,Tp y=p-2){
	Tp res=1;
	for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;
	return res;
}

void PrimeEratosthenes(int n,int *p){//区间[0,n]的质数;
	bool vis[n+1];int i,j;memset(vis,0,sizeof vis);memset(p,0,sizeof p);
	for(i=2;i<=n;i++)if(!vis[i])for(p[++p[0]]=i,j=i+i;j<=n;vis[j]=1,j+=i);
}

void PrimeEuler(int n,int *p){//区间[0,n]的质数;
	bool vis[n+1];memset(p,0,sizeof p);memset(vis,0,sizeof vis);
	for(int i=2;i<=n;i++){if(!vis[i]) p[++p[0]]=i;
	for(int j=1;vis[i*p[j]]=1,i%prime[j]&&j<=p[0]&&i*p[j]<=n;j++);}
}

int Fin(int x){return fat[x]==x?x:fat[x]=Fin(fat[x]);}

template<typename Tp=int>inline Tp read(){
	Tp x=0;int f=0;register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
}

template<typename Tp=int>inline Tp mul_mod(Tp a,Tp b,Tp mo){
	Tp ret;__asm__ __volatile__
	("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mo));
	return ret;
}/* a*b%mo */

for(int k=(1<<n)-1;k<1<<n;){
	/*something else*/
	int x=k&-k,y=k+x;
	k=((k&~y)/x>>1)|y;
}
/*k is the all state of C(n,m);*/
