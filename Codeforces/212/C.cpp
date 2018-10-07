#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
__int64 f[110][2];
char s[110];
int n;
__int64 dp(int k)
{
	memset(f,0,sizeof f);
	f[0][k]=1;
	for(int i=0;i<n;i++)
		if(s[i]=='A') f[i+1][0]+=f[i][0]+f[i][1],f[i+1][1]+=f[i][1]*(s[i+1]!='A');
		else f[i+1][0]+=f[i][1],f[i+1][1]+=f[i][s[i+1]!='A'];
	return f[n][k];
}
int main()
{
	scanf("%s",s);
	s[n=strlen(s)]=s[0];
	cout<<dp(0)+dp(1);
}