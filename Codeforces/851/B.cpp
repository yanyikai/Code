#include<bits/stdc++.h>
using namespace std;
long long ax,ay,bx,by,cx,cy,x,y;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy);
	x=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
	y=(bx-cx)*(bx-cx)+(by-cy)*(by-cy);
	if(x!=y) printf("No");
	else
	{
		if((bx-cx)*(ay-by)==(ax-bx)*(by-cy)) printf("No");
		else printf("Yes");
	}
}