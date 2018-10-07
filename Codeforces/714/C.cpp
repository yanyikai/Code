#include<map>
#include<cstdio>
#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}std::map<int,int>m;
signed main()
{
	int n=read();
	for(int i=0;i<n;++i)
	{
		char c;scanf("%c",&c);
		int k=read(),l=0,x=0;
		for(;k;k/=10,++l)if((k%10)&1)x|=1<<l;
		if(c=='?')printf("%lld\n",m[x]);
		else m[x]+=c=='+'?1:-1;
	}
	return 0;
}
