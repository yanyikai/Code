#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,dp[1<<20][20],u,v,ans,k;
vector<int> head[20];
inline int lowbit(int x) { return x&-x; }
int main()
{
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&u,&v);
		head[u-1].push_back(v-1);
		head[v-1].push_back(u-1);
	}
	for(i=0;i<n;i++) dp[1<<i][i]=1;
	for(i=1;i<1<<n;i++)
		for(j=0;j<n;j++)
			if(dp[i][j])
			{
				int l=head[j].size();
				for(k=0;k<l;k++)
				{
					int t=head[j][k];
					if(lowbit(i)>(1<<t)) continue;
					if((i&(1<<t))&&lowbit(i)==(1<<t)) ans+=dp[i][j];
					if(!(i&(1<<t))) dp[i|(1<<t)][t]+=dp[i][j];
				}
			}
	printf("%lld",(ans-m)/2);
	return 0;
}