#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 300000
using namespace std;
struct Line
{
	int point,next;
}line[N*2+7];
int head[N+7],e,n,i,j,x,y,t[N+7],ans,maxn=-inf,ma,mc,ma_,mc_;
void add(int a,int b)
{
	line[e].point=b;
	line[e].next=head[a];
	head[a]=e;
	e++;
}
int main()
{
	for(scanf("%d",&n),i=1;i<=n;i++) scanf("%d",&t[i]),maxn=max(maxn,t[i]);
	memset(head,-1,sizeof(head));ans=maxn+3;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=n;i++)
	{
		if(t[i]==maxn) ma++,t[i]=2;
		else
		if(t[i]==maxn-1) mc++,t[i]=1;
		else t[i]=0;
	}
//	printf("%d %d %d\n",maxn,ma,mc);
	for(i=1;i<=n;i++)
	{
		if(t[i]==2)
		{
			ma_=0;mc_=0;
			for(j=head[i];j!=-1;j=line[j].next)
			{
				if(t[line[j].point]==1) mc_++;
				else
				if(t[line[j].point]==2) ma_++;
			}
//			printf("%d %d %d %d\n",ma,ma_,mc,mc_);
			if(ma-ma_-1) ans=min(ans,maxn+2);
			else
			{
				if(ma_||mc-mc_) ans=min(ans,maxn+1);
				else
				ans=min(ans,maxn);
			}
		}
//		printf("%d\n",ma);
		else
		{
			ma_=0;
			for(j=head[i];j!=-1;j=line[j].next)
			{
				if(t[line[j].point]==2) ma_++;
			}
			printf("\n\n");
			if(ma_==ma) ans=min(ans,maxn+1);
//			printf("%d %d\n",ma,ma_);
		}
	}
	printf("%d",ans);
	return 0;
}