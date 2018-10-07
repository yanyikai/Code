#include<bits/stdc++.h>
using namespace std;
int n,i;
int main()
{
	scanf("%d",&n);
	i=n/2;
	for(;i>=1;i--)
	{
		if(__gcd(i,n-i)==1)
		{
			printf("%d %d",i,n-i);
			return 0;
		}
	}
	return 0;
}