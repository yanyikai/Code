#include<cstdio>
#include<algorithm>
#define N 200005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int a[N],f[N][205];
int main()
{
	for(int cas=0,T=read();cas<T;++cas)
	{
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read()+a[i-1];
		for(int i=n;~i;--i)
			for(int j=204;j;--j)
			{
				if(i+j>n)f[i][j]=0;else
				if(i+j+1>n)f[i][j]=a[i+j]-a[i]-f[i+j][j];else
				f[i][j]=max(a[i+j]-a[i]-f[i+j][j],a[i+j+1]-a[i]-f[i+j+1][j+1]);
			}
		printf("%d\n",f[0][1]);
	}
	return 0;
}
