#include<bits/stdc++.h>
using namespace std;
int n,a[500],i;
int main()
{
	for(scanf("%d",&n),i=1;i<=2*n;i++) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	a[n]==a[n+1]?printf("NO"):printf("YES");
	return 0;
}