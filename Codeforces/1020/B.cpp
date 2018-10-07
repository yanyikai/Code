#include<bits/stdc++.h>
#define P pair<int,int>
#define N 1005
using namespace std;
int a[N],cnt[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cnt[j]=0;
		int x=i;
		for(;!cnt[x];x=a[x])
			++cnt[x];
		printf("%d ",x);
	}
	return 0;
}
