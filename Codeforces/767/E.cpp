#include<bits/stdc++.h>
#define ii pair<long,long>
#define N 100000
using namespace std;
set<ii> s;long long n,m,x,i,note[N+5],coin[N+5],ans;
int main()
{
	for(scanf("%lld%lld",&n,&m),i=1;i<=n;i++) scanf("%lld",&coin[i]),note[i]=coin[i]/100,coin[i]%=100;
	for(i=1;i<=n;i++)
	{
		m-=coin[i];scanf("%lld",&x);
		if(coin[i]) s.insert(ii(x*(100-coin[i]),i));
		if(m<0)
		{
			m+=100;ans+=s.begin()->first;
			note[s.begin()->second]++;
			coin[s.begin()->second]=0;
			s.erase(s.begin()); 
		}
	}
	for(printf("%lld\n",ans),i=1;i<=n;i++) printf("%lld %lld\n",note[i],coin[i]);
	return 0;
}