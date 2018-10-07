#include<bits/stdc++.h>
using namespace std;
int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97},i,j;
string s;
int main()
{
	do
	{
		if(p[i]>=11)
		{
			printf("prime");
			return 0;
		}
		printf("%d\n",p[i]);
		i++;
		fflush(stdout);
		cin>>s;
	}while(s=="no");
	printf("%d\n",p[i-1]*p[i-1]);
	fflush(stdout);
	cin>>s;
	if(s=="yes")
	{
		printf("composite");
		return 0;
	}
	for(j=i;j<25&&p[i-1]*p[j]<=100;j++)
	{
		printf("%d\n",p[j]);
		fflush(stdout);
		cin>>s;
		if(s=="yes")
		{
			printf("composite");
			return 0;
		}
	}
	printf("prime");
	return 0;
}