#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define int long long
using namespace std;
struct P{int num,id;}a[N];
int num[N],id[N];
void update(int i,int v,int n){for(;i<=n;i+=i&-i)num[i]+=v;}
int Fin(int i){int res=0;for(;i;i-=i&-i)res+=num[i];return res;}
bool cmp(P a ,P b){return a.num<b.num;}
main()
{
   for(int n,m;~scanf("%lld%lld",&n,&m);)
   {
    	for(int i=1;i<=n;++i)
    	{
        	scanf("%lld",&a[i].num);
        	a[i].id=i;
    	}
    	sort(a+1,a+n+1,cmp);
    	int t=0;a[0].num=-1;
    	for(int i=1;i<=n;++i)
    	{
        	if(a[i].num!=a[i-1].num)t++;
        	id[a[i].id]=t;
    	}
    	memset(num,0,sizeof num);
		int sum=0;
    	for(int i=1;i<=n;++i)
    	{
    		sum+=i-1-Fin(id[i]);
        	update(id[i],1,t);
    	}
		printf("%lld\n",max(0ll,sum-m));
   }
   return 0;
}
