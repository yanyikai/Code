#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
	long long a,b,n;
	scanf("%lld%lld%lld",&a,&b,&n);
	n%=6;a=(a+MOD)%MOD;b=(b+MOD)%MOD;
	if(n==1) printf("%lld",a);
	else
	if(n==2) printf("%lld",b);
	else
	if(n==3) printf("%lld",(b-a+MOD)%MOD);
	else
	if(n==4) printf("%lld",(-a+MOD)%MOD);
	else
	if(n==5) printf("%lld",(-b+MOD)%MOD);
	else
	if(n==0) printf("%lld",(a-b+MOD)%MOD);
	return 0;
}