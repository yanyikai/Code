#include<cstdio>
#include<algorithm>
#include<queue>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int a[105],ans=105;
int main()
{
	int n=read(),d=read();
	for(int i=0;i<n;++i)
		a[i]=read();
	sort(a,a+n);if(a[n-1]-a[0]<=d)return puts("0"),0;
	a[n]=105;
	for(int i=0;i<n;++i)
		ans=min(ans,n-int(upper_bound(a,a+n+1,a[i]+d)-a)+i);
	printf("%d\n",ans);
	return 0;
}
