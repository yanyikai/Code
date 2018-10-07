#include<bits/stdc++.h>
using namespace std;
int n,i,k,m[100005],x;
int main()
{
	scanf("%d",&n);k=n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		m[x]++;
		while(m[k]==1)
		{
			printf("%d ",k);
			k--;
		}
		printf("\n");
	}
	return 0;
}