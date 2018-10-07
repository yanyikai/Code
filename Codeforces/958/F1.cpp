#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum[105],b[105];
int check()
{
	for(int i=1;i<=m;++i)
		if(sum[i]!=b[i])
		return 0;
	return 1; 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=m;++i)scanf("%d",b+i);
	for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j)
	{
		for(int k=i;k<=j;++k)
		++sum[a[k]];
		if(check())return puts("YES"),0;
		memset(sum,0,sizeof sum);
	}
	return puts("NO"),0;
}
