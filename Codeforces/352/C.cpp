#include<cmath>
#include<cstdio>
#include<iostream>
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
	int n=read(),num=0;double ans=1e9,sum=0;
	for(int i=0;i<n<<1;++i)
	{
		double t;scanf("%lf",&t);
		int x=t;sum+=t-x;
		if(t==(double)x)++num;
	}
	for(int i=max(0,num-n);i<=min(n,num);++i)
		ans=min(ans,abs(sum-n+i));
	printf("%.3lf",ans);
	return 0;
}
