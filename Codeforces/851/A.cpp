#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int main()
{
	scanf("%d%d%d",&n,&k,&t);
	if(t<=k) printf("%d",t);
	else
	if(t>=n) printf("%d",n+k-t);
	else
	printf("%d",k);
	return 0;
}