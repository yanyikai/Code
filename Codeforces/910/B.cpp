#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,b,ans=0x3f3f3f3f;
void dfs(int aa,int bb,int res,int las)
{
	if(aa==4&&bb==2)
	{
		ans=min(ans,res+1);
		return ;
	}
	if(las<min(a,b))dfs(aa,bb,res+1,n);else
	if(bb==2&&las<a)dfs(aa,bb,res+1,n);else
	if(aa==4&&las<b)dfs(aa,bb,res+1,n);else
	{
	if(las>=a&&aa<4)dfs(aa+1,bb,res,las-a);
	if(las>=b&&bb<2)dfs(aa,bb+1,res,las-b);
	}
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	dfs(0,0,0,n);
	printf("%d",ans);
	return 0;
}
