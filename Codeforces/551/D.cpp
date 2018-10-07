#include<cstdio>
#include<map>
#define int long long
using namespace std;
int n,k,l,p,num;
map<int,int>f;
int Pow(int a,int b)
{
	int res=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)res=res*a%p;
	return res%p;
}
int F(int x)
{
	if(f.count(x))return f[x];
	return f[x]=(F((x+1)/2)*F(x/2)+F(((x-1)/2))*F(x/2-1))%p;
}
main()
{
	scanf("%lld%lld%lld%lld",&n,&k,&l,&p);
	if(l<60&&k>>l)return puts("0"),0;
	f[0]=f[1]=1;int t=(F(n+1)+p)%p;
	for(int i=0;i<l;++i)num+=(k>>i)&1;
	printf("%lld",(Pow((Pow(2ll,n)-t+p)%p,num)%p*Pow(t,l-num)%p+p)%p);
	return 0;
}