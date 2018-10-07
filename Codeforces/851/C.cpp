#include<bits/stdc++.h>
using namespace std;
struct Point
{
	int a,b,c,d,e;
}point[12];
int n,i,j,e,cut,ans[12];
bool p;
int compare(int k,int x,int y)
{
	return (point[k].a-point[x].a)*(point[k].a-point[y].a)+(point[k].b-point[x].b)*(point[k].b-point[y].b)+(point[k].c-point[x].c)*(point[k].c-point[y].c)+(point[k].d-point[x].d)*(point[k].d-point[y].d)+(point[k].e-point[x].e)*(point[k].e-point[y].e);
}
int main()
{
	scanf("%d",&n);
	if(n>11)
	{
		printf("0");
		return 0;
	}
	for(i=1;i<=n;i++) scanf("%d%d%d%d%d",&point[i].a,&point[i].b,&point[i].c,&point[i].d,&point[i].e);
	for(e=1;e<=n;e++)
	{
		p=true;
		for(i=1;i<n;i++)
		{
			if(i==e) continue;
			for(j=i+1;j<=n;j++)
			{
				if(j==e) continue;
				if(compare(e,i,j)>0)
				{
					p=false;
					break;
				}
			}
			if(!p) break;
		}
		if(p)
		{
			ans[0]++;
			cut++;
			ans[cut]=e;
		}
	}
	for(i=0;i<=cut;i++) printf("%d\n",ans[i]);
	return 0;
}