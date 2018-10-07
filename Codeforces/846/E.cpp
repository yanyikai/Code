#include<bits/stdc++.h>
#define N 100000
#define LL long long
using namespace std;
pair<LL,LL> change[N+5];
LL x,n,i;
double need[N+5];
int main()
{
	for(scanf("%lld",&n),i=1;i<=n;i++) scanf("%lf",&need[i]);
	for(i=1;i<=n;i++) scanf("%lld",&x),need[i]=x-need[i];
	for(i=2;i<=n;i++) scanf("%lld%lld",&change[i].first,&change[i].second);
	for(i=n;i>1;need[i]=0,i--) need[change[i].first]+=need[i]>0?1LL*need[i]*change[i].second:need[i];
	need[1]>0?printf("NO"):printf("YES");
	return 0;
}