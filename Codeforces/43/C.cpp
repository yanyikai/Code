#include<cstdio>
using namespace std;
int n,m[3];
long long t;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%lld",&t);
		++m[t%3];
	}
	printf("%d",m[0]/2+(m[1]>m[2]?m[2]:m[1]));
	return 0;
}
