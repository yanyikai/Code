#pragma GCC optimize(3,"inline,Ofast")
#include<cstdio>
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
namespace ScapeGoat{
	#define N 100005
	int rt,son[N][2],cnt[N],val[N],siz[N],fat[N],tot;
	int S[N],top,a[N],_n_;
	int _new(){
		return top?S[top--]:++tot;
	}
	void del(int x){
		if(x[son][0])del(x[son][0]);
		if(x[son][1])del(x[son][1]);
		x[son][0]=x[son][1]=0;S[++top]=x;
	}
	struct Tree{
		int rt;Tree():rt(_new()){}
		void dfs(int x){
			if(x[son][0])dfs(x[son][0]);
			a[++_n_]=x;
			if(x[son][1])dfs(x[son][1]);
		}
		int build(int l,int r){
			if(l>r)return 0;
			int mid=(l+r)>>1,p=a[mid];
			(p[son][0]=build(l,mid))[fat]=p;
			(p[son][1]=build(mid+1,r))[fat]=p;
			p[siz]=p[son][0][siz]+p[son][1][siz]+1;
			return p;
		}
		void rbuild(int x){
			int f=fat[x];_n_=0;dfs(x);
			(f[son][f[son][1]==x]=build(1,_n_))[fat]=f;
		}
		void Ins(int x){
			int rb=-1,f=0;
			for(int p=rt;p;p=p[son][val[p]<x]){
				if(p[fat]&&p[fat]^rt&&!~rb&&p[siz]*5>f[siz]*4)
					rb=f;++(f=p)[siz];
			}if(~rb)rbuild(rb);
		}
		void Del(int x){
		}
		int Fin(int x){
			return 0;
		}
		int Kth(int x){
			return 0;
		}
		int Nxt(int x,int k){
			return 0;
		}
	};
	#undef N
}
int main(){
	int n=read();
	ScapeGoat::Tree T;
	for(int i=0,o,x;i<n;++i){
		o=read(),x=read();
		switch(o){
			case 1:T.Ins(x);break;
			case 2:T.Del(x);break;
			case 3:T.Kth(T.Fin(x));break;
			case 4:T.Kth(x);break;
			case 5:T.Nxt(x,0);break;
			case 6:T.Nxt(x,1);break;
		}
	}
    return 0;
}
