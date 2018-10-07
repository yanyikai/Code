#include<cstdio>
#include<algorithm>
#define N 100005
#define L long long
#define int long long
inline L read(){
	L x=0;int f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
L k[N],a[N],b[N],num[N];
signed main()
{
	int m=read();
	for(int i=1;i<=m;++i)
	{
		k[i]=read();
		if(k[i]==1)
		{
			a[i]=read();
			num[i]=num[i-1]+1;
		}else
		{
			a[i]=read();
			b[i]=read();
			num[i]=num[i-1]+a[i]*b[i];
		}
	}
	int n=read();
	for(int i=0;i<n;++i)
	{
		L now=read(),pos=lower_bound(num+1,num+m+1,now)-num;
		for(;k[pos]==2;)
		{
			now-=num[pos-1];
			now=(now-1)%a[pos]+1;
			pos=lower_bound(num+1,num+m+1,now)-num;
		}
		printf("%lld ",a[pos]);
	}
	return 0;
}
