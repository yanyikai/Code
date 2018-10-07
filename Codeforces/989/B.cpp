#include<bits/stdc++.h>
using namespace std;
int n,p;char s[2005];
inline int get()
{
	for(int l=0,r;(r=l+p)<n;++l)
	{
		if(s[l]!=s[r])
		{
			if(s[l]=='.')s[l]=97-s[r];else
			if(s[r]=='.')s[r]=97-s[l];
			return 0;
		}else if(s[l]=='.')
		{
			s[l]=49;s[r]=48;
			return 0;
		}
	}return 1;
}
int main()
{
	scanf("%d%d%s",&n,&p,s);
//	puts("-1");
	if(get())puts("No");else
	for(int i=0;i<n;++i)
		putchar(s[i]=='.'?48:s[i]);
	return 0;
}
