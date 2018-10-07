#include<bits/stdc++.h>
#define N 0
#define P pair<L,L>
#define L long long
using namespace std;
int n,i,a,b,c,d;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=4;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(min(a,b)+min(c,d)<=n)
		{
			printf("%d %d %d",i,min(a,b),n-min(a,b));
			return 0;
		}
	}
	printf("-1");
	return 0;
}