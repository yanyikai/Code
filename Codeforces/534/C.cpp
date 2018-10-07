#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL d[200000],n,A,i,sum;
int main()
{
	for(scanf("%lld%lld",&n,&A),i=0;i<n;i++) scanf("%lld",&d[i]),sum+=d[i];
	for(i=0;i<n;i++) printf("%lld ",max((LL)0,d[i]-A-1+n)+max((LL)0,A-sum+d[i]-1));
	return 0;
}