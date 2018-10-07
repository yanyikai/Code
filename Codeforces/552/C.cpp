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
int main()
{
	int w=read(),m=read();
	for(;m;m/=w)if(m%w>1&&m%w<w-1)return puts("NO"),0;else m+=m%w>1;
	return puts("YES"),0;
}
