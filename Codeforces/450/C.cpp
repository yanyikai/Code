#include<bits/stdc++.h>
using namespace std;
long long n,k,m;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k>n+m-2) return 0*puts("-1");
	printf("%lld",max(n/(min(n-1,k)+1)*m/(k-min(n-1,k)+1),m/(min(m-1,k)+1)*n/(k-min(m-1,k)+1)));
	return 0;
}