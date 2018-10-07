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
int m[1024],tmp[1024];
int main()
{
	int n=read(),k=read(),x=read();
	for(int i=0;i<n;++i)++m[read()];
	for(int i=0;i<k;++i)
	{
		int now=1;
		for(int i=0;i<1024;++i)
		{
			tmp[i]+=(m[i]+(now^1))>>1;
			tmp[(i^x)]+=(m[i]+now)>>1;
			now=(now+m[i])&1;
		}
		for(int i=0;i<1024;++i)
			m[i]=tmp[i],tmp[i]=0;
	}
	for(int i=1023;;--i)
	if(m[i])
	{
		printf("%d ",i);
		break;
	}
	for(int i=0;;++i)
	if(m[i])
	{
		printf("%d\n",i);
		break;
	}
	return 0;
}
