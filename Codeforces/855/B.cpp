#include<bits/stdc++.h>
#define N 100005
#define INF 0x7f7f7f7f
#define L long long
using namespace std;
L n,k1,k2,k3,p1,p3,t[N],ans=-5*1e18,l[N],r[N],x;
int i;
priority_queue<L> ll,rr;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k1,&k2,&k3);
	for(i=1;i<=n;i++) scanf("%I64d",&t[i]);
	k1<0?p1=-1:p1=1;k3<0?p3=-1:p3=1;
	for(i=1;i<=n;i++) ll.push(p1*t[i]),l[i]=p1*ll.top();
	for(i=n;i>=1;i--) rr.push(p3*t[i]),r[i]=p3*rr.top();
	for(i=1;i<=n;i++) ans=max(ans,k2*t[i]+k1*l[i]+k3*r[i]);
	printf("%I64d",ans);
	return 0;
}