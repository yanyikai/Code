#include<cstdio>
using namespace std;
int stc[1000005],n,i,x,t;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&x);
		for(;t>0&&stc[t]>=i-x;--t);
		stc[++t]=i;
	}
	printf("%d",t);
	return 0;
}
