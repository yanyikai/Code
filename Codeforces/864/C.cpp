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
//#define Debug
//#define File
using namespace std;
int a,b,f,k,i,ans,n;
vector<int> v;
int main()
{
	#ifdef File
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
	scanf("%d%d%d%d",&a,&b,&f,&k);
	v.push_back(0);n=b;
	for(i=0;i<k;i++) i&1?v.push_back(a-f+a*i):v.push_back(f+a*i);
	v.push_back(a*i);
	for(i=0;i<k+1;i++)
	{
		if(n<0) return 0*puts("-1");
		if(n<v[i+1]-v[i]) n=b,ans++;
		n-=(v[i+1]-v[i]);
	}
	if(n<0) return 0*puts("-1");
	printf("%d",ans);
	return 0;
}
