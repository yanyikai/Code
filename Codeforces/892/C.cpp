#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,i,j,a[2000];
inline int get(int res)
{
	if(res) return n-res;
	if(n==1) return -1;
	for(i=1;i<n;++i)
		for(j=0;j+i<n;++j)
			if((a[j]=__gcd(a[j],a[j+1]))==1) return i+n-1;
	return -1;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",a+i);
		if(a[i]==1) ++ans;
	}
	printf("%d",get(ans));
	return 0;
}
