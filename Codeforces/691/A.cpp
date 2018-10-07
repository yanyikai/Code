#include<bits/stdc++.h>
using namespace std;
bool p;
int n,i,x;
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%d",&x);
		x?puts("YES"):puts("NO");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==0&&p) return 0*puts("NO");
		if(x==0) p=true;
	}
	if(p==false) return 0*puts("NO");
	return 0*puts("YES");
}