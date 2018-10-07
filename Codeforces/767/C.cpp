#include<bits/stdc++.h>
using namespace std;
struct Line
{
	int point,next;
}line[1000005];
int head[1000005],k[1000005],i,ii,n,e,sum,v,j,ans_1,ans_2,ans[5];
void add(int u,int v)
{
	line[e].point=v;
	line[e].next=head[u];
	head[u]=e;
	e++;
}
void dfs(int i)
{
	int p=head[i];
	while(p!=-1)
	{
		dfs(line[p].point);
		k[i]+=k[line[p].point];
		p=line[p].next;
	}
	if(k[i]==sum&&i!=ii) ans[++ans[0]]=i,k[i]=0;
	if(ans[0]==2)
	{
		printf("%d %d",ans[2],ans[1]);
		exit(0);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&v,&k[i]);
		if(v) add(v,i);
		else ii=i;
		sum+=k[i];
	}
	if(sum%3) printf("-1");
	else
	{
		sum/=3;
		dfs(ii);
		if(ans[0]!=2) printf("-1");
	}
	return 0;
}