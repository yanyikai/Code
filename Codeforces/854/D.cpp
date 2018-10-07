#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct Fly
{
	int day,city,cost;
	bool operator<(const Fly &x) const
	{
		return day<x.day;
	}
};
vector<Fly> fly_from,fly_to;
long long dp[N+7][2],cost[N+7],tot,ans=-1;
int n,m,k,i,d,f,t,c,p,e;
int main()
{
	fly_from.clear(),fly_to.clear();
	memset(dp,-1,sizeof(dp));
	for(scanf("%d%d%d",&n,&m,&k),i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&d,&f,&t,&c);
		f?fly_to.push_back({d,f,c}):fly_from.push_back({d,t,c});
	}
	sort(fly_from.begin(), fly_from.end());
	sort(fly_to.begin(), fly_to.end());
	memset(cost,-1,sizeof(cost));p=tot=e=0;
	for(i=1;i<=N;i++)
	{
		while(p<fly_to.size()&&fly_to[p].day==i)
		{
			if (cost[fly_to[p].city]==-1)
			{
				e++;
				cost[fly_to[p].city]=fly_to[p].cost;
				tot+=fly_to[p].cost;
			}
			else
			if(cost[fly_to[p].city]>fly_to[p].cost)
			{
				tot-=(cost[fly_to[p].city]-fly_to[p].cost);
				cost[fly_to[p].city]=fly_to[p].cost;
			}
			p++;
		}
		if(e==n) dp[i][0]=tot;
	}
	p=fly_from.size()-1;e=tot=0;memset(cost,-1,sizeof(cost));
	for(i=N;i>=1;i--)
	{
		while(p>=0&&fly_from[p].day==i)
		{
			if(cost[fly_from[p].city]==-1)
			{
				e++;
				cost[fly_from[p].city]=fly_from[p].cost;
				tot+=fly_from[p].cost;
			}
			else
			if(cost[fly_from[p].city]>fly_from[p].cost)
			{
				tot-=(cost[fly_from[p].city]-fly_from[p].cost);
				cost[fly_from[p].city]=fly_from[p].cost;
			}
			p--;
		}
		if(e==n) dp[i][1]=tot;
	}
	for(i=1;i<=N;i++)
	{
		if(dp[i][0]!=-1&&i+k+1<=1e6&&dp[i+k+1][1]!=-1)
		{
			ans==-1?ans=dp[i][0]+dp[i+k+1][1]:ans=min(ans,dp[i][0]+dp[i+k+1][1]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}