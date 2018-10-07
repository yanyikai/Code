#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
int tot,tre[N][26],num[N],dp[N][2];
char s[N];
void dfs(int u)
{
	int sum=0;
	for(int i=0;i<26;++i)
		if(tre[u][i])
		{
			dfs(tre[u][i]);sum=1;
			dp[u][0]|=!dp[tre[u][i]][0];
			dp[u][1]|=!dp[tre[u][i]][1];
		}
	if(!sum)dp[u][1]=1;
}
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		for(int i=0,j=0;s[i];++i)j=tre[j][s[i]-'a']?tre[j][s[i]-'a']:tre[j][s[i]-'a']=++tot;
	}dfs(0);
	puts(dp[0][0]?(dp[0][1]?"First":k&1?"First":"Second"):"Second");
	return 0;
}