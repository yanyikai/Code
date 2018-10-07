#include<cstdio>
#define int long long
inline long long read(){
	long long x=0;int f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
long long num[100];
signed main()
{
	int n=read();
	for(int i=0;i<n;++i)
	{
		int op=read(),l=0;long long x=read();
		for(;1ll<<l<=x;++l);--l;
		if(op==3)
		{
			x=((x+num[l])&((1ll<<l)-1))|(1ll<<l);
			for(;x>1;x>>=1,--l)
			printf("%lld ",((x-num[l])&((1ll<<l)-1))|(1ll<<l));
			puts("1");
		}else
		{
			int k=read();
			int top=op==1?l:60;
			for(;l<=top;++l,k<<=1)num[l]=(num[l]+k)&((1ll<<l)-1);
		}
	}
	return 0;
}
