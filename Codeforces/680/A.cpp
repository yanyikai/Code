#include <bits/stdc++.h>
using namespace std;
bool com(int x,int y)
{
	if(x!=y)return x>y;
}
int main()
{
	int a[5];
	int flag=0,s=0;
	scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	sort(a,a+5,com);
	for(int i=0;i<5;i++)
	s+=a[i];
	int min=s;
	for(int i=0;i<=5;i++)
	{
		if(a[i]==a[i+1]&&a[i]==a[i+2]&&min>s-3*a[i])
		min=s-3*a[i];
		if(a[i]==a[i+1]&&a[i]!=a[i+2]&&min>s-2*a[i])
		min=s-2*a[i];
	}
	printf("%d",min);
	return 0;
}
