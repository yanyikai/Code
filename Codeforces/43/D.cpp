#include<cstdio>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int main()
{
	int n=read(),m=read();
	if(n==1&&m==1)return puts("0\n1 1"),0;
	if(n==1&&m==2)return puts("0\n1 1\n1 2\n1 1"),0;
	if(n==2&&m==1)return puts("0\n1 1\n2 1\n1 1"),0;
	if(n==1)
	{
		printf("1\n1 %d 1 1\n",m);
		for(int i=1;i<=m;++i)
		printf("1 %d\n",i);puts("1 1");
		return 0;
	}
	if(m==1)
	{
		printf("1\n%d 1 1 1\n",n);
		for(int i=1;i<=n;++i)
		printf("%d 1\n",i);puts("1 1");
		return 0;
	}
	if(n&1&&m&1)
	{
		printf("1\n%d %d 1 1\n",n,m);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		printf("%d %d\n",i,i&1?j:m-j+1);
		puts("1 1");
		return 0;
	}puts("0\n1 1");
	if(n&1)
	{
		for(int j=1;j<=m;++j)
		for(int i=2;i<=n;++i)
		printf("%d %d\n",j&1?i:n-i+2,j);
		for(int i=m;i;--i)
		printf("1 %d\n",i);
		return 0;
	}
	if(m&1)
	{
		for(int i=1;i<=n;++i)
		for(int j=2;j<=m;++j)
		printf("%d %d\n",i,i&1?j:m-j+2);
		for(int i=n;i;--i)
		printf("%d 1\n",i);
		return 0;
	}
	for(int j=1;j<=m;++j)
	for(int i=2;i<=n;++i)
	printf("%d %d\n",j&1?i:n-i+2,j);
	for(int i=m;i;--i)
	printf("1 %d\n",i);
	return 0;
}
