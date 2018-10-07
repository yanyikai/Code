#include<cstdio>
#include<cmath>
#define N 25
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
long long S[N][N],fac[N];
int main()
{
	**S=*fac=1;
	for(int i=1;i<N;++i)
	{
		for(int j=1;j<=i;++j)
			S[i][j]=S[i-1][j]*(i-1)+S[i-1][j-1];
		fac[i]=fac[i-1]*i;
	}
	for(int cas=0,T=read();cas<T;++cas)
	{
		int n=read(),k=read();
		long long sum=0;
		for(int i=1;i<=k;++i)
			sum+=S[n][i]-S[n-1][i-1];
		printf("%.4lf\n",1.0*sum/fac[n]);
	}
	return 0;
}

