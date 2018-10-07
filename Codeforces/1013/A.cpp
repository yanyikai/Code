#include<cstdio>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int x,sum;
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&x),sum+=x;
	for(int i=0;i<n;++i)scanf("%d",&x),sum-=x;
	if(sum<0)puts("No");else puts("Yes");
	return 0;
}
