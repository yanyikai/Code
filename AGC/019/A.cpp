#include<cstdio>
#include<algorithm>
#define int long long
inline int read(){
	int x=0;char ch=getchar();
	for(;ch<48||ch>57;ch=getchar());
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
signed main()
{
	int a=read(),b=read(),c=min(read(),min(a*4,b*2)),d=min(read(),c*2),n=read();
	printf("%lld\n",(n>>1)*d+(n&1)*c);
	return 0;
}