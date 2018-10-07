#include<cstdio>
#include<iostream>
#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
signed main()
{
	int n=read(),k=read(),A=read(),B=read(),ans=0;
	if(k==1)return printf("%lld\n",(n-1)*A),0;
	for(;n!=1;)
	{
		if(n%k)
		{
			int now=n%k;
			if((n-now)==0)ans+=(n-1)*A,n=1;
			else ans+=now*A,n-=now;
		}else
		{
			ans+=min(B,(n-n/k)*A);
			n/=k;
		}
	}printf("%lld\n",ans);
	return 0;
}
