#include<bits/stdc++.h>
#define inf 10000000
using namespace std;
int stc[200005];
int n,ans,nospeed=inf,unovertake,top,speed,x,i;
int main()
{
	for(scanf("%d",&n),i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&speed);
			while(top&&stc[top]<speed)
			{
				ans++;
				top--;
			}
		}
		else 
		if(x==2)
		{
			if(unovertake)
			{
				ans+=unovertake;
				unovertake=0;
			}
		}
		else
		if(x==3)
		{
			scanf("%d",&nospeed);
			if(speed>nospeed)
			{
				ans++;
			}
			else
			{
				stc[++top]=nospeed;
			}
		}
		else
		if(x==4)
		{
			unovertake=0;
		}
		else
		if(x==5)
		{
			nospeed=inf;
			stc[++top]=nospeed;
		}
		else
		if(x==6)
		{
			unovertake++;
		}
	}
	printf("%d",ans);
	return 0;
}