#include<bits/stdc++.h>
#define N 100005
#define mid ((l+r)>>1)
#define ls l,mid,o<<1
#define rs mid+1,r,o<<1|1
using namespace std;
struct P{int x,y;}p[N];vector<int>v[N<<2];
int x[N],y[N],a[9],b[9],c[9],sx[2],sy[2],fx[2],fy[2],n;
void build(int l,int r,int o)
{
	for(int i=l;i<=r;++i)v[o].push_back(p[i].y);
	if(l==r)return ;
	sort(v[o].begin(),v[o].end());
	build(ls),build(rs);
}
int Q(int l,int r,int o,int L,int R)
{
	if(p[l].x> L)return 0;
	if(p[r].x<=L)return upper_bound(v[o].begin(),v[o].end(),R)-v[o].begin();
	return Q(ls,L,R)+Q(rs,L,R);
}
void get()
{
	sx[0]=c[0]+c[3]+c[6],sx[1]=sx[0]+c[1]+c[4]+c[7];
	sy[0]=c[0]+c[1]+c[2],sy[1]=sy[0]+c[3]+c[4]+c[5];
	for(int i=0;i<2;++i)
		if(x[sx[i]]==x[sx[i]+1]||y[sy[i]]==y[sy[i]+1])return ;
	for(int i=0;i<2;++i)
		fx[i]=x[sx[i]],fy[i]=y[sy[i]];
	if(Q(1,n,1,fx[0],fy[0])!=c[0]
	|| Q(1,n,1,fx[0],fy[1])!=c[0]+c[3]
	|| Q(1,n,1,fx[1],fy[0])!=c[0]+c[1]
	|| Q(1,n,1,fx[1],fy[1])!=c[0]+c[1]+c[3]+c[4])return ;
	printf("%.8lf %.8lf\n%.8lf %.8lf",(double)fx[0]+0.5,(double)fx[1]+0.5,(double)fy[0]+0.5,(double)fy[1]+0.5);
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",x+i,y+i),p[i]=P{x[i],y[i]};
	sort(x+1,x+n+1);sort(y+1,y+n+1);
	sort(p+1,p+n+1,[](P a,P b)->int{return a.x<b.x;});
	for(int i=0;i<9;++i)scanf("%d",a+i),b[i]=i;build(1,n,1);
	do{for(int i=0;i<9;++i)c[i]=a[b[i]];get();
	}while(next_permutation(b,b+9));
	return puts("-1"),0;
}