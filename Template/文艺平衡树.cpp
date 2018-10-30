#include<cstdio>
#include<iostream>
#define N 100100
namespace splay
{
	#define R register
	static int key[N],son[N][2],siz[N],fat[N],tag[N],rt,tot;
	inline void PU(int x){x[siz]=x[son][0][siz]+x[son][1][siz]+1;}
	inline void PD(int x)
	{
		if(!x[tag])return ;
		x[tag]=0;
		x[son][0][tag]^=1;
		x[son][1][tag]^=1;
		std::swap(x[son][0],x[son][1]);
	}
	inline void Rot(int x)
	{
		R int y=fat[x],z=fat[y],k=son[y][0]==x;
		z[son][son[z][1]==y]=x;x[fat]=z;
		y[son][!k]=x[son][k];x[son][k][fat]=y;
		x[son][k]=y;y[fat]=x;PU(y);
	}
	inline void Spl(int x,int goal)
	{
		for(PD(x);x[fat]!=goal;Rot(x))
		{
			R int y=x[fat],z=y[fat];
			if(z!=goal)(y[son][0]==x)^(z[son][0]==y)?Rot(x):Rot(y);
		}PU(x);if(!goal)rt=x;
	}
	inline int Kth(int k)
	{
		for(R int x=rt;;)
		{
			PD(x);
			R int y=x[son][0];
			if(k>y[siz]+1)
			{
				k-=y[siz]+1;
				x=x[son][1];
			}else
			if(k>y[siz])return x;
			else x=y;
		}
	}
	inline void Rev(int l,int r)
	{
		if(l>r)l^=r,r^=l,l^=r;
		R int x=Kth(l),y=Kth(r+2);
		Spl(x,0);Spl(y,x);
		y[son][0][tag]^=1;
	}
	inline void Ins(int val,int p=siz[rt]-2)
	{
		Spl(Kth(p+1),0);
		R int x=++tot;
		for(x[fat]=rt[son][1];x[fat][son][0];x[fat]=x[fat][son][0]);
		x[fat][son][0]=x;x[key]=val;x[son][0]=x[son][1]=0;Spl(x,0);
	}
	inline void Del(int p=siz[rt]-2)
	{
		R int x=Kth(p),y=Kth(p+2);
		Spl(x,0);Spl(y,x);
		y[son][0]=0;PU(y);PU(rt);
	}
	int build(int *a,int fa,int l,int r)
	{
		if(l>r)return 0;
		R int mid=(l+r)>>1,x=++tot;
		x[fat]=fa;x[key]=a[mid];
		x[son][0]=build(a,x,l,mid-1);
		x[son][1]=build(a,x,mid+1,r);
		PU(x);return x;
	}
	void put(int x)
	{
		PD(x);
		if(x[son][0])put(x[son][0]);
		if(x[key]>-1e9&&x[key]<1e9)printf("%d ",x[key]);
		if(x[son][1])put(x[son][1]);
	}
}using namespace splay;
int main()
{
	Ins(-1e9);Ins(+1e9);
}
