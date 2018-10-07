#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,x,n,m,f[20005];
main()
{
	scanf("%lld%lld%lld%lld",&k,&x,&n,&m);
	for(int i=0;i<=n>>1;++i)for(int j=0;j<=m>>1;++j)
	for(int a=0;a<2;++a)for(int b=0;b<2;++b)for(int c=0;c<2;++c)for(int d=0;d<2;++d)
	{
		if(i*2+a+b>n||j*2+c+d>m)continue;
		f[1]=i;f[2]=j;
		for(int t=3;t<=k;++t)
		{
			f[t]=f[t-1]+f[t-2];
			if(t==3&&b+c==2)++f[t];
			if(t>3&&(((t&1)&&d+c==2)||((t&1)==0&&a+d==2)))++f[t];
		}
		if(f[k]==x)
		{
			if(a)printf("C");
			for(int t=1;t<=i;++t)printf("AC");
			for(int t=1;t<=n-2*i-a-b;++t)printf("X");
			if(b)printf("A");putchar('\n');
			if(c)printf("C");
			for(int t=1;t<=j;++t)printf("AC");
			for(int t=1;t<=m-2*j-c-d;++t)printf("Y");
			if(d)printf("A");putchar('\n');
			return 0;
		}
	}
	printf("Happy new year!\n");
	return 0;
}