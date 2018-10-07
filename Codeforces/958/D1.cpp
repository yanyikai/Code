#include<bits/stdc++.h>
using namespace std;
char s[105];
int n,t0[200005],t1[200005],res[205][105];
inline int gcd(int a,int b)
{
	for(;b;b^=a^=b^=a%=b);
	return a;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int a,b,c;scanf("%s",s);
		sscanf(s,"(%d+%d)/%d\n",&a,&b,&c);
		a+=b;
		if(a)
		{
			int g=gcd(a,c);
			++res[t0[i]=a/g][t1[i]=c/g];
		}else
			++res[t0[i]=0][t1[i]=0];
	}
	for(int i=0;i<n;++i)
		printf("%d ",res[t0[i]][t1[i]]);
	return 0;
}
