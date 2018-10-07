#include<bits/stdc++.h>
using namespace std;
int n,ans,a,b;
int main()
{
	scanf("%d",&n);
	if(n%2)
	{
		printf("0");
		return 0;
	}
	n/=2;a=1;b=n-1;
	while(b>a)
	{
		ans++;
		a++;
		b--;
	}
	printf("%d",ans);
	return 0;
}