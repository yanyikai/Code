#include<bits/stdc++.h>
using namespace std;
int cur,k,n,i;
int main()
{
	scanf("%d",&n);n*=2;
	if(n==0)
	{
		printf("a");
		return 0;
	}
	while(n)
	{
		k=1;
		while(k*(k+1)<=n)
		{
			k++;
		}
		n-=k*(k-1);
		for(i=1;i<=k;i++)
		{
			printf("%c",cur+'a');
		}
		cur++;
	}
	return 0;
}