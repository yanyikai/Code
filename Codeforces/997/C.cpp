#include<iostream>
#define L long long
using namespace std;
L p=998244353,ans,n;
L P(L x,L y)
{
	L res=1;
	for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;
	return res;
}
int main()
{
	cin>>n;
	ans=P(3,n*n)-P(P(3,n)-3,n);
	for(L i=0,t=1;i<=n;++i)
	{
		L b=P(3,n-i);
		L res=t*(P(b,n)-P(b-(i?1:3)+p,n))%p;
		if(i)res=res*3%p;
		ans+=i&1?-res:res;
		t=t*(n-i)%p*P(i+1,p-2)%p;
	}
	cout<<(ans%p+p)%p;
	return 0;
}
