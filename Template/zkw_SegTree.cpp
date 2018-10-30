#define ls(x) x<<1
#define rs(x) x<<1|1
template<typename Tp> class ST
{
	private:
		Tp t[N<<2];
		int dl[N<<2],dr[N<<2],lazy[N<<2],M;
		inline void getM(int n) { for(M=1;M<n-1;M<<=1); }
		void PushDown(int x)
		{
			int stack[20],top=0;
			for(;x;x>>=1) stack[++top]=x;
			while(--top) HaveDown(stack[top]);
		}
	public:
		void build(int n)
		{
			getM(n);memset(lazy,0,sizeof lazy);
			for(int i=1;i<=n;i++) scanf("%lld",&t[M+i]),dl[M+i]=dr[M+i]=i;
			for(int i=M-1;i>=1;i--) PushUp(i),dl[i]=dl[ls(i)],dr[i]=dr[rs(i)];
		}
};
/*
PushUp:
	max:inline void PushUp(int x) { t[x]=max(t[ls(x)],t[rs(x)]); }
	min:inline void PushUp(int x) { t[x]=min(t[ls(x)],t[rs(x)]); }
	sum:inline void PushUp(int x) { t[x]=t[ls(x)]+t[rs(x)]; }
section:
	HaveDown:
		add:
			inline void HaveDown(int x)
			{
				if(!lazy[x]||x>=M) return ;
				lazy[ls(x)]+=lazy[x],lazy[rs(x)]+=lazy[x];
				t[ls(x)]+=lazy[x]*(dr[ls(x)]-dl[ls(x)]+1);
				t[rs(x)]+=lazy[x]*(dr[rs(x)]-dl[rs(x)]+1);
				lazy[x]=0;
			}
		change:
			inline void HaveDown(int x)
			{
				if(!lazy[x]||x>=M) return ;
				t[ls(x)]=lazy[x]*(dr[ls(x)]-dl[ls(x)]+1);
				t[rs(x)]=lazy[x]*(dr[rs(x)]-dl[rs(x)]+1);
				lazy[ls(x)]=lazy[rs(x)]=lazy[x];lazy[x]=0;
			}
	Update:
		add:
			void Update(int l,int r,int val)
			{
				int insl=0,insr=0;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1)
					{
						if(!insl) PushDown(insl=l^1);
						lazy[l^1]+=val;
						t[l^1]+=(Tp)val*(dr[l^1]-dl[l^1]+1);
					}
					if(r&1)
					{
						if(!insr) PushDown(insr=r^1);
						lazy[r^1]+=val;
						t[r^1]+=(Tp)val*(dr[r^1]-dr[r^1]+1);
					}
				}
				for(insl>>=1;insl;insl>>=1) PushUp(insl);
				for(insr>>=1;insr;insr>>=1) PushUp(insr);
			}
		change:
			void Update(int l,int r,int val)
			{
				int insl=0,insr=0;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1)
					{
						if(!insl) PushDown(insl=l^1);
						lazy[l^1]=val;
						t[l^1]=(Tp)val*(dr[l^1]-dl[l^1]+1);
					}
					if(r&1)
					{
						if(!insr) PushDown(insr=r^1);
						lazy[r^1]=val;
						t[r^1]=(Tp)val*(dr[r^1]-dr[r^1]+1);
					}
				}
				for(insl>>=1;insl;insl>>=1) PushUp(insl);
				for(insr>>=1;insr;insr>>=1) PushUp(insr);
			}
	Query:
		sum:
			Tp Query(int l,int r)
			{
				Tp res=0;
				int insl=0,insr=0;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1)
					{
						if(!insl) PushDown(insl=l^1);
						res+=t[l^1];
					}
					if(r&1)
					{
						if(!insr) PushDown(insr=r^1);
						res+=t[r^1];
					}
				}
				return res;
			}
		max:
			Tp Query(int l,int r)
			{
				Tp res=-INF;
				int insl=0,insr=0;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1)
					{
						if(!insl) PushDown(insl=l^1);
						res=max(res,t[l^1]);
					}
					if(r&1)
					{
						if(!insr) PushDown(insr=r^1);
						res=max(res,t[r^1]);
					}
				}
				return res;
			}
		min:
			Tp Query(int l,int r)
			{
				Tp res=INF;
				int insl=0,insr=0;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1)
					{
						if(!insl) PushDown(insl=l^1);
						res=min(res,t[l^1]);
					}
					if(r&1)
					{
						if(!insr) PushDown(insr=r^1);
						res=min(res,t[r^1]);
					}
				}
				return res;
			}
point:
	Update:
		add:
			void Update(int p,int val) { for(p+=M;p;p>>=1) t[p]+=val; }
		change:
			void Update(int p,int val) { for(p+=M;p;p>>=1) t[p]=val; }
	Query:
		sum:
			Tp Query(int l,int r)
			{
				Tp res=0;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1) res+=t[l^1];
					if(r&1) res+=t[r^1];
				}
				return res;
			}
		max:
			Tp Query(int l,int r)
			{
				Tp res=-INF;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1) res=max(res,t[l^1]);
					if(r&1) res=max(res,t[r^1]);
				}
				return res;
			}
		min:
			Tp Query(int l,int r)
			{
				Tp res=INF;
				for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
				{
					if(~l&1) res=min(res,t[l^1]);
					if(r&1) res=min(res,t[r^1]);
				}
				return res;
			}
*/
