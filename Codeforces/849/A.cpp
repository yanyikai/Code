#include<bits/stdc++.h>
using namespace std;
int i,n,x;
int main()
{
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("No");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i==1||i==n)
		{
			if(x%2==0)
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
	return 0;
}