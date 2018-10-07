#include<bits/stdc++.h>
using namespace std;
int n,sum,x;
int main()
{
	scanf("%d",&x);
	x=abs(x);
	for(int i=1;i<=1000000;i++)
	{
		sum=i*(i-1)/2;
		if(sum==x) return 0*printf("%d",i-1);
		if(sum>x)
		{
			if((sum-x)%2==0)
			{
				if((sum-x)/2<sum) return 0*printf("%d",i-1);
			}
		}
	}
	return 0;
}