#include<bits/stdc++.h>
#define L long long
using namespace std;
void gcd(int a,int b,L&x,L&y,int c)
{
	if(!b){x=c;y=0;return ;}
	gcd(b,a%b,y,x,c);y-=a/b*x;
}
int main()
{
	int n,m,x,y,vx,vy;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&vx,&vy);
	if(!vx)
	{
		if(!x||x==n)printf("%d %d",x,~vy?m:0);
		else puts("-1");return 0;
	}
	if(!vy)
	{
		if(!y||y==m)printf("%d %d",~vx?n:0,y);
		else puts("-1");return 0;
	}
	int k1=~vx?(n-x)%n:x%n,k2=~vy?(m-y)%m:y%m;
	int g=n,p=m;for(;p;p^=g^=p^=g)g%=p;
	if((k1-k2)%g)return puts("-1"),0;
	L xx,yy,s,lcm=1ll*n/g*m;
	gcd(n,m,xx,yy,(k2-k1)/g);
	xx%=m/g;s=((xx*n+k1)%lcm+lcm)%lcm;
	xx=x+s*vx;yy=y+s*vy;n<<=1;m<<=1;
	printf("%lld %lld",(xx%n+n)%n,(yy%m+m)%m);
	return 0;
}
