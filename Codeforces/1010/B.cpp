#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,mid,p[100],i,j;
void ask(int x)
{
	cout<<x<<'\n';
	fflush(stdout);
	cin>>j;
}
main()
{
	cin>>m>>n;
	for(i=1;i<=n;i++){ask(1);if(!j)exit(0);p[i]=j;}
	for(i=l=1,r=m;;i=i%n+1)
	{
		ask(mid=l+r>>1);
		j*=p[i];if(!j)exit(0);
		~j?l=mid+1:r=mid-1;
	}
}
