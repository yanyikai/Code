#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	printf("%d\n",a[n-(n>>1)]);
	return 0;
}
