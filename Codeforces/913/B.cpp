#include<cstdio>
int n,i,f[1005],d[1005],a[1005];
main()
{
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",f+i);
		++d[f[i]];
	}
	for(i=1;i<=n;++i)if(!d[i])++a[f[i]];
	for(i=1;i<=n;++i)if(d[i]&&a[i]<3)break;
	puts(i>n?"Yes":"No");
}
