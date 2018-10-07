#include<bits/stdc++.h>
#define F1(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define pi acos(-1.0)
#define L long long
#define E long double
#define D double
#define P pair<int,int>
#define st first
#define nd second
#define INFI 0x3f3f3f3f
#define INFL 0x7f7f7f7f
#define N 200005
#define M 
#define MS(n,v) memset(n,v,sizeof(n));
#define OP() freopen("???.in","r",stdin);
#define ED() freopen("???.out","w",stdout);
//#define int long long
//#define %d %lld
using namespace std;
int cnt,l,t,k,fa[N],a[N],n;
vector<int> pio[N];
int main()
{
	scanf("%d%d%d",&n,&t,&k);
	F1(i,1,t) scanf("%d",&a[i]);a[0]=1;
	F1(i,0,t) F1(j,1,a[i]) pio[i].push_back(++cnt);
	F1(i,0,a[1]-1) fa[pio[1][i]]=1;
	F1(i,2,t) fa[pio[i][0]]=pio[i-1][0];
	l=n-t-k;
	F1(i,2,t)
	{
		F1(j,1,a[i]-1)
		{
			if(l>0&&j<a[i-1]) fa[pio[i][j]]=pio[i-1][j],l--;
			else fa[pio[i][j]]=pio[i-1][0];
		}
	}
	if(l) return 0*puts("-1");
	printf("%d\n",n);
	F1(i,2,n) printf("%d %d\n",i,fa[i]);
	return 0;
}