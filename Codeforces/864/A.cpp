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
#define N         
#define M         
#define MS(n,v)   memset(n,v,sizeof(n));
//#define int       long long
//#define %d        %I64d
//#define Debug
//#define File
using namespace std;
int n,a[10000],x,y,xx,yy;
bool p1,p2,p3;
map<int,int> m;
int main()
{
	#ifdef File
		freopen("A.in","r",stdin);
		freopen("A.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m[a[i]]++;
		if(m.size()>2) return 0*puts("NO");
	}
	if(m.size()==1) return 0*puts("NO");
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) if(it==m.begin()) x=it->second,xx=it->first;else y=it->second,yy=it->first;
	if(x!=y) return 0*puts("NO");
	printf("YES\n%d %d",xx,yy);
	return 0;
}
