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
int num[15];
int main()
{
	int n=read(),l=0,x=0;
	for(;n;n/=10)num[++l]=n%10;
	for(;l;--l)if(num[l])
	{
		x+=1<<(l-1);
		if(num[l]>1)return printf("%d\n",x+(1<<(l-1))-1),0;
	}printf("%d\n",x);
	return 0;
}
