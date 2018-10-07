#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;scanf("%lld",&n);
	++n;
	if(n==1)return puts("0"),0;
	if(n==2)return puts("1"),0;
	if(n==3)return puts("3"),0;
	if(n==4)return puts("2"),0;
	if(n==5)return puts("5"),0;
	printf("%lld\n",n&1?n:n/2);
	return 0;
}
