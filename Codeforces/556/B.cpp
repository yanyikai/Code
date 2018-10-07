#include<bits/stdc++.h>
using namespace std;
int n,a[1005],i;
bool check(int k)
{
	for(int i=0;i<n;i++)
	{
		int t;
		if(i&1) t=(a[i]-k+n)%n;
		else t=(a[i]+k)%n;
		if(t!=i) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) if(check(i)) return 0*puts("YES");
	return 0*puts("NO");
}
