#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,k; 
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k<n)return printf("%lld 1",k+1),0;
	k-=n;
	long long x=k/(m-1),y=k%(m-1);
	printf("%lld %lld\n",n-x,x&1?m-y:y+2);
	return 0;
}
