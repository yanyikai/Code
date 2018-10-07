#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int n,i,watch_time[3];
ii t[200005];
bool cmp(ii x,ii y)
{
	return x.first==y.first?x.second<y.second:x.first<y.first;
}
int main()
{
	watch_time[1]=watch_time[2]=-1;
	for(scanf("%d",&n),i=0;i<n;i++) scanf("%d%d",&t[i].first,&t[i].second);
	sort(t,t+n,cmp);
	for(i=0;i<n;i++)
	{
		if(t[i].first>watch_time[1])
		{
			watch_time[1]=t[i].second;
			continue;
		}
		if(t[i].first>watch_time[2])
		{
			watch_time[2]=t[i].second;
			continue;
		}
		return 0*puts("NO");
	}
	printf("YES");
	return 0;
}