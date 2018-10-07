#include<bits/stdc++.h>
#define F(i,x,y) for(int i=x;i<=y;i++)
#define N 1000005
using namespace std;
int n,m,p[N],u,v,fa[N],pos[N],cnt;
priority_queue<int> pqi[N],pq[N];
inline int f(int i) { return fa[i]==i?i:fa[i]=f(fa[i]); }
int main()
{
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",&p[i]),fa[i]=i;
	F(i,1,m) scanf("%d%d",&u,&v),fa[f(u)]=f(v);
	F(i,1,n) if(fa[i]==i) pos[i]=++cnt;
	F(i,1,n) pq[pos[f(i)]].push(p[i]),pqi[pos[f(i)]].push(-i);
	F(i,1,cnt) while(!pq[i].empty()) p[-pqi[i].top()]=pq[i].top(),pq[i].pop(),pqi[i].pop();
	F(i,1,n) printf("%d ",p[i]);
	return 0;
}