#include<bits/stdc++.h>
#define E long double
using namespace std;
map<E,int> m;int n,a,x,y;
int main()
{
	for(scanf("%d",&n);n--;)
	{
		scanf("%d%d",&x,&y);
		if(!x) continue;
		if(!m[(E)y/x]) m[(E)y/x]=1,a++;
	}
	return 0*printf("%d",a);
}