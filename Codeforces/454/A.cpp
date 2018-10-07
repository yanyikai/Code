#include<bits/stdc++.h>
using namespace std;
int n,i,j;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n/2;i++)
	{
		for(j=1;j<=n/2-i+1;j++) printf("*");
		for(j=1;j<=1+2*(i-1);j++) printf("D");
		for(j=1;j<=n/2-i+1;j++) printf("*");
		printf("\n");
	}
	for(i=1;i<=n;i++) printf("D");
	printf("\n");
	for(i=n/2;i>=1;i--)
	{
		for(j=1;j<=n/2-i+1;j++) printf("*");
		for(j=1;j<=1+2*(i-1);j++) printf("D");
		for(j=1;j<=n/2-i+1;j++) printf("*");
		printf("\n");
	}
	return 0;
}
