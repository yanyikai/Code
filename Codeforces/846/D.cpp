#include<cstdio>
#include<algorithm>
using namespace std;
struct Point
{
	int x,y,t;
	bool operator<(const Point& b) const
	{
		return t<b.t;
	}
}p[255000];
int b[510][510];
bool c[510][510];
int n,m,k,q;
bool judge(int x,int y)
{
	int i,ans=0;
	for(i=x;i<=n;i++)
	{
		if(b[i][y]<k)
			break;
		ans++;
		if(ans>=k)	break;
	}
	for(i=x-1;i>=1;i--)
	{
		if(b[i][y]<k)
			break;
		ans++;
		if(ans>=k)	break;
	}
	if(ans>=k)
		return true;
	else
		return false;
}
int main()
{
	int i,j;
	bool boo;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(i=1;i<=q;i++)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
	sort(p+1,p+q+1);
	for(i=1;i<=q;i++)
	{
		int& x=p[i].x;
		int& y=p[i].y;
		c[x][y]=true;
		for(j=y;j>=1;j--)
		{
			if(!c[x][j])	break;
			b[x][j]=b[x][j+1]+1;
			if(b[x][j]>=k)
			{
				boo=judge(x,j);
				if(boo==true)
				{
					printf("%d",p[i].t);
					return 0;
				}
			}
		}
	}
	printf("-1");
	return 0;
}