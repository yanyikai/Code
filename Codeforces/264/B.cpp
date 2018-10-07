#include<bits/stdc++.h>
#define N 100005
using namespace std;
int dp[N];
vector<int>pri;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		pri.clear();
		int x;scanf("%d",&x);
		int t=sqrt(x);
		pri.push_back(x);
		for(int i=2;i<=t;++i)
		{
			if(i*i==x){pri.push_back(i);continue;}
			if(x%i==0)
				pri.push_back(i),
				pri.push_back(x/i);
		}
		// for(int i:pri)
		// 	printf("%d ",i);puts("");
		int mxn=0;
		for(int i:pri)
			mxn=max(mxn,++dp[i]);
		for(int i:pri)
			dp[i]=mxn;
	}
	int mxn=0;
	for(int i=1;i<N;++i)
		mxn=max(mxn,dp[i]);
	printf("%d\n",mxn);
	return 0;
}