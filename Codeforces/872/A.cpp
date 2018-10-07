#include<bits/stdc++.h>
using namespace std;
int n,m,k1[10],k2[10],m1=10,m2=10,i,j,x;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		m1=min(m1,x);
		k1[x]++;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		m2=min(m2,x);
		k2[x]++;
	}
	for(i=1;i<=9;i++) if(k1[i]&&k2[i]) return 0*printf("%d",i);
	printf("%d%d",min(m1,m2),max(m1,m2));
	return 0;
}
