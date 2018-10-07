#include<cstdio>
using namespace std;
int Pow(int x,long long y){
	int res=1;
	for(;y;y>>=1,x=x*x%100)if(y&1)res=res*x%100;
	return res;
}
int main()
{
	for(int T;~scanf("%d",&T)&&T;puts(""))
		for(int cas=1;cas<=T;++cas)
		{
			long long n;
			scanf("%lld",&n),--n,
			printf("Case %d: %d\n",cas,(Pow(4,n)+Pow(2,n))%100);
		}
	return 0;
}
