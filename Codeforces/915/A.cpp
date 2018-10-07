#include<bits/stdc++.h>
using namespace std;
int n,k,t,ma;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		if(k%t==0&&t>ma)ma=t;
	}
	printf("%d",k/ma);
	return 0;
}
