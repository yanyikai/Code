#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[105],b[105],i,j;
int main()
{
	memset(b,0x3f3f3f3f,sizeof b);
	scanf("%d%d\n",&n,&m);b[0]=0;
	for(i=0;i<n;++i)a[i]=getchar()-'0';
	for(i=1;i<n;++i)
	{
		if(!a[i])continue;
		for(j=max(i-m,0);j<i;++j)
			if(a[j])b[i]=min(b[i],b[j]+1);
	}
	printf("%d",b[n-1]==0x3f3f3f3f?-1:b[n-1]);
	return 0;
}
