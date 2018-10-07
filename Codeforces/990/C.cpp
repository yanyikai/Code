#include<cstdio>
#define N 300005
//#include<vector>
#include<cstring>
#define int long long
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
char s[N];int m[N][2],sum;
signed main()
{
	int n=read();
	for(int j=0;j<n;++j)
	{
		scanf("%s",s);
		int l=strlen(s),a=0,b=0;
		for(int i=0;i<l;++i)
		{
			if(s[i]=='(')++a;
			if(s[i]==')')a?--a:++b;
		}
		if(a&&b)continue;
		if(a)++m[a][0];
		if(b)++m[b][1];
		if(!a&&!b)++m[0][0],++m[0][1];
	}
	for(int i=0;i<N;++i)
		sum+=m[i][0]*m[i][1];
	printf("%lld\n",sum);
	return 0;
}
