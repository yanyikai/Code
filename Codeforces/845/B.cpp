#include<bits/stdc++.h>
using namespace std;
int n,i,b,a[10],sum;
char c;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	for(i=1;i<=6;i++) scanf("%c",&c),a[i]=c-'0';
	b=a[1]+a[2]+a[3]-a[4]-a[5]-a[6];
	if(b)
	{
		i=0;
		if(b>0)
		{
			a[4]=9-a[4];
			a[5]=9-a[5];
			a[6]=9-a[6];
			sort(a+1,a+7,cmp);
			while(sum<b)
			{
				sum+=a[++i];
			}
		}
		else
		{
			b=abs(b);
			a[1]=9-a[1];
			a[2]=9-a[2];
			a[3]=9-a[3];
			sort(a+1,a+7,cmp);
			while(sum<b)
			{
				sum+=a[++i];
			}
		}
		printf("%d",i);
	}
	else printf("0");
	return 0;
}
