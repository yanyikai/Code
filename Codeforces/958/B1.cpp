#include<cstdio>
using namespace std;
int n,m,a[10005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		++a[x];++a[y]; 
	}
	for(int i=1;i<=n;++i)
		if(a[i]==1)ans++;
	printf("%d\n",ans); 
	return 0;
}
