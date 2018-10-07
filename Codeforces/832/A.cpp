#include<bits/stdc++.h>
using namespace std;
long long x,y;
int main()
{
	scanf("%lld%lld",&x,&y);
	x=x/y;y=x%2;
	y?printf("YES"):printf("NO");
	return 0;
}