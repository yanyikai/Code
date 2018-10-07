#include<bits/stdc++.h>
using namespace std;
int i,n,x,d[100005],l;
int main()
{
	for(scanf("%d",&n),i=0;i<n;i++)
	{
		scanf("%d",&x);
		i?x>=d[l]?d[++l]=x:d[upper_bound(d+1,d+l+1,x)-d]=x:d[++l]=x;
	}
	printf("%d",l);
	return 0;
}