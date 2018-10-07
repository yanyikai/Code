#include<cstdio>
#include<algorithm>
#define N 1000005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
char s[N],a[N];
int main()
{
	int n=read(),k=read();
	scanf("%s",s);
	for(int i=0;i<n;++i)
	a[i]=s[i];sort(a,a+n);
	int tot=(unique(a,a+n)-a);
	if(k>n)
	{
		printf("%s",s);
		k-=n;
		for(int i=0;i<k;++i)putchar(a[0]);
		return 0;
	}int pos=-1;
	for(int i=k-1;~i;--i)
		if(s[i]!=a[tot-1])
		{
			pos=i;
			break;
		}
	for(int i=0;i<k;++i)
	{
		if(i==pos)
		{
			putchar(*upper_bound(a,a+tot,s[i]));
			pos=-1;
		}else
		if(pos==-1)
		{
			putchar(a[0]);
		}else putchar(s[i]);
	}
	return 0;
}
