#include<cstdio>
#include<algorithm>
#define N 100005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int a[N],b[N],t[5],l=-1e9,r=1e9;
int main()
{
	int n=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=0;i<n;++i)scanf("%1d",b+i);
	for(int i=4;i<n;++i)
	{
		for(int j=0;j<5;++j)t[j]=a[j+i-4];
		sort(t,t+5);
		if(b[i]!=b[i-1])
		{
			if(b[i])
				l=max(l,t[4]+1);
			else
				r=min(r,t[0]-1);
		}
	}printf("%d %d\n",l,r);
	return 0;
}
