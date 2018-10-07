#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int p[200010],t[200010];
int n,w,k,l,r,ans,v,tim;
multiset<int> ms,que;
multiset<int>::iterator it;
int main()
{
	scanf("%d%d%d",&n,&w,&k);
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	for(int i=0;i<n;i++) scanf("%d",&t[i]);
	while(r<n)
	{
		tim+=(t[r]+1)/2;
		v+=p[r];
		ms.insert(t[r++]);
		if(ms.size()>w)
		{
			que.insert(*(ms.begin()));
			tim+=*(ms.begin())/2;
			ms.erase(ms.begin());
		}
		while(l<=r&&tim>k)
		{
			if(t[l]>=*(ms.begin()))
			{
				tim-=(t[l]+1)/2;
				ms.erase(ms.find(t[l]));
				if(que.size())
				{
					it=que.end();
					ms.insert(*(--it));
					tim-=*it/2;
					que.erase(it);
				}
			}
			else que.erase(que.find(t[l])),tim-=t[l];
			v-=p[l++];
		}
		ans=max(ans,v);
	}
	printf("%d",ans);
	return 0;
}
