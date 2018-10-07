#include<cstdio>
main()
{
	int n,x,cnt=0;
	scanf("%d",&n);
	if(n<=5)return puts("Petr"),0;
	for(int i=1;i<=n;i++)scanf("%d",&x),cnt+=(i==x);
	puts(cnt>2?"Petr":"Um_nik");
}
