#include<bits/stdc++.h>
using namespace std;
int x,y,i,n;
int main()
{
	scanf("%d",&n);
	scanf("%d",&x);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&y);
		printf("%d ",x+y);
		x=y;
	}
	printf("%d",x);
	return 0;
}