#include<bits/stdc++.h>
#define SumTree
#define SectionChange
#define N 100000
#define INF 0x3f3f3f3f
class SegTree
{
	#define ls l,m,rt<<1
	#define rs m+1,r,rt<<1|1
	public:
		int t[N<<2],lazy[N<<2];
		inline int max(int a,int b) { return a>b?a:b; }
		inline int min(int a,int b) { return a<b?a:b; }
	public:
		SegTree() { memset(lazy,0,sizeof lazy); }
		#ifdef SumTree
			inline void PushUp(int rt) { t[rt]=t[rt<<1]+t[rt<<1|1]; }//sum_tree;
			int Query(int L,int R,int l,int r,int rt)//sum;
			{
				if(L<=l&&r<=R) return t[rt];
				int m=(l+r)>>1,ans=0;
				#ifdef SectionAdd
					PushDown(rt,r-l+1);//section_add or _change;
				#else
					#ifdef SectionChange
						PushDown(rt,r-l+1);//section_add or _change;
					#endif
				#endif
				if(L<=m) ans+=Query(L,R,ls);
				if(R> m) ans+=Query(L,R,rs);
				return ans;
			}
		#endif
		#ifdef MaxTree
			inline void PushUp(int rt) { t[rt]=max(t[rt<<1],t[rt<<1|1]); }//max_tree;
			int Query(int L,int R,int l,int r,int rt)//max;
			{
				if(L<=l&&r<=R) return t[rt];
				int m=(l+r)>>1,ans=-INF;
				#ifdef SectionAdd
					PushDown(rt,r-l+1);//section_add or _change;
				#else
					#ifdef SectionChange
						PushDown(rt,r-l+1);//section_add or _change;
					#endif
				#endif
				if(L<=m) ans=max(ans,Query(L,R,ls));
				if(R> m) ans=max(ans,Query(L,R,rs));
				return ans;
			}
		#endif
		#ifdef MinTree
			inline void PushUp(int rt) { t[rt]=min(t[rt<<1],t[rt<<1|1]); }//min_tree;
			int Query(int L,int R,int l,int r,int rt)//min;
			{
				if(L<=l&&r<=R) return t[rt];
				int m=(l+r)>>1,ans=INF;
				#ifdef SectionAdd
					PushDown(rt,r-l+1);//section_add or _change;
				#else
					#ifdef SectionChange
						PushDown(rt,r-l+1);//section_add or _change;
					#endif
				#endif
				if(L<=m) ans=min(ans,Query(L,R,ls));
				if(R> m) ans=min(ans,Query(L,R,rs));
				return ans;
			}
		#endif
		#ifdef SectionChange
			inline void PushDown(int rt,int len)//section_change;
			{
				if(!lazy[rt]) return ;
				lazy[rt<<1]=lazy[rt];
				lazy[rt<<1|1]=lazy[rt];
				t[rt<<1|1]=lazy[rt]*(len>>1);
				t[rt<<1]=lazy[rt]*(len-(len>>1));
				lazy[rt]=0;
			}
		#endif
		#ifdef SectionAdd
			inline void PushDown(int rt,int len)//section_add;
			{
				if(!lazy[rt]) return ;
				lazy[rt<<1]+=lazy[rt];
				lazy[rt<<1|1]+=lazy[rt];
				t[rt<<1|1]+=lazy[rt]*(len>>1);
				t[rt<<1]+=lazy[rt]*(len-(len>>1));
				lazy[rt]=0;
			}
		#endif
		#ifdef PointChange
			void Update(int p,int val,int l,int r,int rt)//point_change;
			{
				if(l==r) t[rt]=val;
				else
				{
					int m=(l+r)>>1;
					p>m?Update(p,val,rs):Update(p,val,ls);
					PushUp(rt);
				}
			}
		#endif
		#ifdef PointAdd
			void Update(int p,int val,int l,int r,int rt)//point_add;
			{
				if(l==r) t[rt]+=val;
				else
				{
					int m=(l+r)>>1;
					p>m?Update(p,val,rs):Update(p,val,ls);
					PushUp(rt);
				}
			}
		#endif
		#ifdef SectionAdd
			void Update(int L,int R,int val,int l,int r,int rt)//section_add;
			{
				if(L<=l&&r<=R) lazy[rt]+=val,t[rt]+=val*(r-l+1);
				else
				{
					int m=(l+r)>>1;
					PushDown(rt,r-l+1);
					if(L<=m) Update(L,R,val,ls);
					if(R> m) Update(L,R,val,rs);
					PushUp(rt);
				}
			}
		#endif
		#ifdef SectionChange
			void Update(int L,int R,int val,int l,int r,int rt)
			{
				if(L<=l&&r<=R) lazy[rt]=val,t[rt]=val*(r-l+1);
				else
				{
					PushDown(rt,r-l+1);
					int m=(l+r)>>1;
					if(L<=m) Update(L,R,val,ls);
					if(R> m) Update(L,R,val,rs);
					PushUp(rt);
				}
			}
		#endif
		void build(int l,int r,int rt)
		{
			t[rt]=1;lazy[rt]=0;
			if(l==r) return ;
			int m=(l+r)>>1;
			build(ls),build(rs);
			PushUp(rt);
		}
	#undef ls
	#undef rs
}tree;
int main()
{
	int T,n,m,l,r,val;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&n,&m);
		tree.build(1,n,1);
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&val);
			tree.Update(l,r,val,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas,tree.t[1]);
	}
	return 0;
}
