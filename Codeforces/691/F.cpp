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
#define N         3000005
#define M         
#define MS(n,v)   memset(n,v,sizeof(n));
//#define Debug
//#define File
using namespace std;
long long n,m[N],x,sum[N],k;
int main()
{
	#ifdef File
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
	scanf("%lld",&n);
	F1(i,1,n) scanf("%lld",&x),m[x]++;
	F1(i,1,2000) for(int j=i;m[i]&&i*j<=N-5;j++) i-j?sum[i*j]+=m[i]*m[j]:sum[i*j]+=(m[i]-1)*m[i]/2;
	F1(i,1,N-5) sum[i]+=sum[i-1];
	scanf("%lld",&k);
	F1(i,1,k)
	{
		scanf("%lld",&x);
		printf("%lld\n",n*(n-1)-2*sum[x-1]);
	}
	return 0;
}