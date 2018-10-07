#include<cstdio>
//#include<vector>
//#include<cstring>
#include<algorithm>
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
	int n=read(),m=read(),a=read(),b=read();
	int t=n/m*m;
	if(t==n)return puts("0"),0;
	printf("%lld\n",min((n%m)*b,(m-n%m)*a));
	return 0;
}
