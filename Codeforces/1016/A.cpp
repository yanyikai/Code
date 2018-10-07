#include<cstdio>
using namespace std;
int main()
{
	int n,m,las=0;
	scanf("%d%d",&n,&m);
	for(int i=0,x;i<n;++i)
	{
		scanf("%d",&x);
		x+=las;
		printf("%d ",x/m);
		las=x%m;
	}
	return 0;
}
