#include<cstdio>
#define N 500100
namespace Splay
{
	#define R register
	static int son[N][2],fat[N],key[N],val[N],siz[N],rt,tot,pos;
	inline void PU(int x){siz[x]=son[x][0][siz]+son[x][1][siz]+val[x];}
	inline void Rot(int x)
	{
		R int y=fat[x],z=fat[y],k=son[y][0]==x;
		son[z][son[z][1]==y]=x;fat[x]=z;
		son[y][!k]=son[x][k];son[x][k][fat]=y;
		son[x][k]=y;fat[y]=x;PU(y);
	}
	inline void Spl(int x,int goal)
	{
		for(;fat[x]!=goal;Rot(x))
		{
			R int y=fat[x],z=fat[y];
			if(z!=goal)(son[y][0]==x)^(son[z][0]==y)?Rot(x):Rot(y);
		}PU(x);if(!goal)rt=x;
	}
	inline void Fin(int x)
	{for(pos=rt;son[pos][x>key[pos]]&&x!=key[pos];pos=son[pos][x>key[pos]]);Spl(pos,0);}
	inline void Nex(int x,int k)
	{
		Fin(x);if(!(key[pos]>x&&k||key[pos]<x&&!k))
		for(pos=son[pos][k];son[pos][!k];pos=son[pos][!k]);
	}
	inline void Ins(int x)
	{
		R int fa=0;
		for(pos=rt;pos&&key[pos]!=x;pos=son[pos][x>key[pos]])fa=pos;
		if(pos)++val[pos];else
		{
			pos=++tot;
			son[fa][x>key[fa]]=pos;
			son[pos][0]=son[pos][1]=0;
			fat[pos]=fa;key[pos]=x;val[pos]=siz[pos]=1;
		}Spl(pos,0);
	}
	inline void Del(int x)
	{
		Nex(x,0);R int next=pos;
		Nex(x,1);R int last=pos;
		Spl(next,0);Spl(last,next);
		pos=son[last][0];
		if(val[pos]>1)--val[pos],--siz[pos];
		else son[last][0]=0;PU(last);PU(next);
	}
	inline void Kth(int k)
	{
		for(pos=rt;;)
		{
			R int y=son[pos][0];
			if(k>siz[y]+val[pos])
			{
				k-=siz[y]+val[pos];
				pos=son[pos][1];
			}else
			if(siz[y]<k)return ;
			else pos=y;
		}
	}
	inline void put(int p)
	{
		if(son[p][0])put(son[p][0]);
		printf("!%d %d %d %d\n",key[p],val[p],siz[p],fat[p]);
		if(son[p][1])put(son[p][1]);
	}
	inline void rput(){for(int i=1;i<=tot;++i)printf("!%d %d %d %d\n",key[i],val[i],siz[i],fat[i]);} 
}using namespace Splay;
int main()
{
	Ins(-1e9);Ins(+1e9);
}
