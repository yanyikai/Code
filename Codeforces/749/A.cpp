#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%d\n",n/2);
	if(n&1)
	{
		for(int i=1;i<=n/2-1;i++)
		{
			printf("2 ");
		}
		printf("3");
	}
	else
	{
		for(int i=1;i<=n/2;i++) printf("2 ");
	}
	return 0;
}