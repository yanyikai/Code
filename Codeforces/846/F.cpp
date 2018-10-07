#include<bits/stdc++.h>
const int N=1e6;
using namespace std;
int pre[N+10],v[N+10],n,x,i;
long long ans;
int main()
{
	for(scanf("%d",&n),i=1;i<=n;i++)
	{
		scanf("%d",&x);pre[i]=v[x];v[x]=i;ans+=((long long)(n-pre[i])*(n-pre[i])-(long long)(i-pre[i]-1)*(i-pre[i]-1)-(long long)(n-i)*(n-i));
	}
	printf("%.12lf",(double)ans/n/n);
	return 0;
}