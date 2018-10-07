#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,x,l;
int main()
{
	scanf("%d%d",&n,&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x);
			if(x==j) l++;
		}
	}
	printf("%d",2*(n-l)-k+1);
}
