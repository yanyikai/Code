#include<bits/stdc++.h>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
map<int,int>m,p;
int a[100005],ans;
int main()
{
	int n,x;scanf("%d%d",&n,&x);
	for(int i=0;i<n;++i)
		scanf("%d",a+i),
		++m[a[i]];
	for(int i=0;i<n;++i)
	{
		if(m[a[i]]>1)return puts("0"),0;
		--m[a[i]];
		if(m[a[i]&x])ans=1;
		++m[a[i]];
	}
	if(ans)return puts("1"),0;
	for(int i=0;i<n;++i)
		++p[a[i]&x];
	for(auto v:p)if(v.second>1)return puts("2"),0;
	puts("-1");
	return 0;
}
