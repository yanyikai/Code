#include<bits/stdc++.h>
using namespace std;
int i,l,r,x,y;
double k;
int main()
{
	scanf("%d%d%d%d%lf",&l,&r,&x,&y,&k);
	for(i=x;i<=y;i++)
	{
		if((double)i*k<=r&&(double)i*k>=l)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}