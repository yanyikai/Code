#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int p[10005],T;
char s[10005],t[1000005];
void getp(int n)
{
	p[0]=-1;
	for(int i=1,j=-1;i<=n;i++)
	{
		while(j>=0&&s[j+1]!=s[i]) j=p[j];
		p[i]=++j;
	}
}
int KMP(int n,int m)
{
	int ans=0;
	for(int i=1,j=0;i<=m;i++)
	{
		while(j>=0&&s[j+1]!=t[i]) j=p[j];
		j++;
		if(j==n) ans++,j=0;
	}
	return ans;
}
int main()
{
	while(true)
	{
		scanf("%s",t+1);
		if(t[1]=='#') break;
		scanf("%s",s+1);
		getp(strlen(s+1));
		printf("%d\n",KMP(strlen(s+1),strlen(t+1)));
	}
	return 0;
}
