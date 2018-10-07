#include<cstdio>
#define N 300005
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
bool ans[1005][1005];
signed main()
{
	int n=read(),a=read(),b=read();
	if(a>1&&b>1)return puts("NO"),0;
	if(a==1&&b==1)
	{
		if(n==2||n==3)
			return puts("NO"),0;
		puts("YES");
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=n;++j)
				putchar(j==i+1||j==i-1?49:48);
		return 0;
	}
	puts("YES");
	if(a==1)
	{
		if(n==b)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					ans[i][j]=i!=j;
		else
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
				{
					if(j>i)ans[i][j]=i<b;
					if(j==i)ans[i][j]=0;
					if(j<i)ans[i][j]=n-i+1<b;
				}
	}else
	{
		if(n==a)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					ans[i][j]=i!=j;
		else
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
				{
					if(j>i)ans[i][j]=i<a;
					if(j==i)ans[i][j]=0;
					if(j<i)ans[i][j]=n-i+1<a;
				}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j)ans[i][j]=ans[i][j]!=1;
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)
		{
			if(j<i)putchar(ans[j][i]?49:48);
			else putchar(ans[i][j]?49:48);
		}
	return 0;
}
