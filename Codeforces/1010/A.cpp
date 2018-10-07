#include<cstdio>
main()
{
	int n,m,i,x;
	scanf("%d%d",&n,&m);
	double w=m;
	for(i=1;i<=n<<1;i++)
	{
		scanf("%d",&x);
		if(x==1)return puts("-1"),0;
		w=w*x/(x-1);
	}if(w>=m)printf("%.10f",w-m);
}
