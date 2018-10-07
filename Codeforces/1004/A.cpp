#include<cstdio>
#include<algorithm>
using namespace std;
int a[105],ans;
int main()
{
	int n,d;scanf("%d%d",&n,&d);
	d<<=1;
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
	sort(a,a+n);
	for(int i=1;i<n;++i)
		ans+=(a[i]-a[i-1]>d)+(a[i]-a[i-1]>=d);
	printf("%d",ans+2);
	return 0;
}
