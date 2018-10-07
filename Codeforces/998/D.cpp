#include<bits/stdc++.h>
using namespace std;
int n,B,a[102],c,d[102],k,i;
main()
{
	cin>>n>>B;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<n;++i)
	{
	    a[i]&1?++c:--c;
		if(!c)d[k++]=abs(a[i]-a[i+1]);
	}sort(d,d+k);
	for(i=0;i<k&&B>=d[i];++i)B-=d[i];
	cout<<i;
}
