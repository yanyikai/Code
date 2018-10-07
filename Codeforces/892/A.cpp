#include<cstdio>
#include<algorithm>
using namespace std;
long long sum,x,a[100005],n,i;
int main()
{
	scanf("%lld",&n);
	for(i=0;i<n;++i) scanf("%lld",&x),sum+=x;
	for(i=0;i<n;++i) scanf("%lld",a+i);
	sort(a,a+n);
	puts(sum>a[n-1]+a[n-2]?"NO":"YES");
	return 0;
}
