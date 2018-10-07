#include<bits/stdc++.h>
using namespace std;
struct Hw { int d,c;char s[105]; }hw[20];
struct DP { int t,ans,last,now; }dp[(1<<15)+5];
int T,n,i,j,k,cnt;
stack<int> s;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		for(memset(dp,0,sizeof dp),scanf("%d",&n),i=0;i<n;i++) scanf("\n%s%d%d",hw[i].s,&hw[i].d,&hw[i].c);
		for(i=1;i<(1<<n);i++) for(dp[i].ans=1<<30,j=n-1;j>=0;j--) if(i&(k=1<<j)) if(max(dp[i-k].t+hw[j].c-hw[j].d,0)+dp[i-k].ans<dp[i].ans) dp[i]={dp[i-k].t+hw[j].c,max(dp[i-k].t+hw[j].c-hw[j].d,0)+dp[i-k].ans,i-k,j};
		for(printf("%d\n",dp[k=(1<<n)-1].ans);k;k=dp[k].last) s.push(dp[k].now);
		while(!s.empty()) printf("%s\n",hw[s.top()].s),s.pop();
	}
	return 0;
}
