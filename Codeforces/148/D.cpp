#include<cstdio>
int w,b,k,s;double d,p,q=1;
main()
{
	scanf("%d%d",&w,&b);
	for(s=w+b;k<s;--s,++k)
	{
		d=q*w/s;p+=d;q-=d;
		q-=q*w/(--s);
	}
	printf("%.9lf",p);
}