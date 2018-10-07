#include<cstdio>
#include<cstring>
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
int up[55][55],f[2][8];
main()
{
	for(int cas=1,T=read();cas<=T;++cas)
	{
		memset(up,0,sizeof up);
		int n=read(),m=read(),ans=0;
		for(int i=0;i<m;++i)
		{
			int k=read();
			for(int j=0;j<k;++j)
				up[i][read()-1]=1;
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k)
				{
					memset(f,0,sizeof f);**f=1;
					for(int e=0;e<m;++e)
					{
						int sta=up[e][i]+up[e][j]*2+up[e][k]*4;
						for(int t=0;t<8;++t)
							f[(e+1)&1][t]=(f[e&1][t]+f[e&1][t^sta])%(int)(1e9+7);
					}
					(ans+=f[m&1][7])%=(int)(1e9+7);
				}
		printf("Case #%lld: %lld\n",cas,ans);
	}
	return 0;
}
