#include<bits/stdc++.h>
#define F1(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define pi        acos(-1.0)
#define L         long long
#define E         long double
#define D         double
#define P         pair<int,int>
#define st        first
#define nd        second
#define pb        push_back
#define mp        make_pair
#define INFI      0x3f3f3f3f
#define INFL      0x7f7f7f7f
#define MOD       1000000007
#define N         200005
#define M
#define MS(n,v)   memset(n,v,sizeof(n));
//#define int       long long
//#define %d        %I64d
//#define Debug
//#define File
using namespace std;
int p=1,a[N],ans=0,n,i;
int vis[N],k[N];
int main()
{
#ifdef File
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	scanf("%d",&n);
	memset(vis,false,sizeof(vis));
	for(i=1; i<=n; i++) scanf("%d",&a[i]),vis[a[i]]++;
	for(i=1; i<=n; i++)
	{
		if(vis[a[i]]==1) continue;
		for(; vis[p]>0; p++);
		if(p>n) break;
		if(p>a[i]&&!k[a[i]])
		{
			k[a[i]]=1;
		}
		else
		{
			ans++;
			vis[a[i]]--;
			a[i]=p;
			vis[p]++;
		}
	}
	printf("%d\n",ans);
	for(i=1; i<=n; i++) printf("%d ",a[i]);
	return 0;
}
