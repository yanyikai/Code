#include<bits/stdc++.h>
using namespace std;
int r,d,n,x,y,R,ans;
double k;
int main()
{
	scanf("%d%d%d",&r,&d,&n);d=r-d;
	while(n--)
	{
		scanf("%d%d%d",&x,&y,&R);
		k=sqrt(x*x+y*y);
		if((double)k-R>=d&&(double)k+R<=r) ans++;
	}
	printf("%d",ans);
	return 0;
}