#include<bits/stdc++.h>
std::pair<int,int>a[22];
int b[22],n,i;
main()
{
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}std::sort(a,a+n);
	for(i=1;i<=n;++i) b[a[i%n].second]=a[i-1].first;
	for(i=0;i<n;++i) printf("%d ",b[i]);
}
