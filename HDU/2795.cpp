#include<bits/stdc++.h>
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
const int N=200000;
int h,w,n,wi;
struct Seg_Tree
{
	int t[N<<2];
	inline void Sum(int rt) { t[rt]=t[rt<<1]+t[rt<<1|1]; }
	inline void Max(int rt) { t[rt]=max(t[rt<<1],t[rt<<1|1]); }
	inline void Min(int rt) { t[rt]=min(t[rt<<1],t[rt<<1|1]); }
	void build(int l,int r,int rt)
	{
		if(l==r) t[rt]=w;
		else
		{
			int m=(l+r)>>1;
			build(ls),build(rs),Max(rt);
		}
	}
	int Query(int val,int l,int r,int rt)
	{
		if(l==r)
		{
			t[rt]-=val;
			return l;
		}
		int m=(l+r)>>1,res=(t[rt<<1]>=val)?Query(val,ls):Query(val,rs);
		Max(rt);
		return res;
	}
}tree;
int main()
{
	while(~scanf("%d%d%d",&h,&w,&n))
	{
		h=min(h,n);
		tree.build(1,h,1);
		while(n--)
		{
			scanf("%d",&wi);
			printf("%d\n",tree.t[1]<wi?-1:tree.Query(wi,1,h,1));
		}
	}
	return 0;
}
