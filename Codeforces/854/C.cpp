#include<bits/stdc++.h>
#define N 300000
#define ii pair<int,int>
using namespace std;
struct Heap
{
	int s;ii heap[N+5];
	void init()
	{
		s=0;
	}
	void push(ii x)
	{
		int i=++s;
		ii t;
		heap[s]=x;
		while(i/2>=1&&heap[i].first>heap[i/2].first)
		{
			t=heap[i];
			heap[i]=heap[i/2];
			heap[i/2]=t;
			i/=2;
		}
	}
	ii top()
	{
		return heap[1];
	}
	void pop()
	{
		int i=1,mx;
		ii t;
		heap[1]=heap[s];heap[s].first=heap[s].second=0;s--;
		while(i*2<=s&&(heap[i].first<heap[i*2].first||heap[i].first<heap[i*2+1].first))
		{
			heap[i*2].first>heap[i*2+1].first?mx=i*2:mx=i*2+1;
			t=heap[mx];
			heap[mx]=heap[i];
			heap[i]=t;
			i=mx;
		}
	}
	bool empty()
	{
		return !s;
	}
	int size()
	{
		return s;
	}
}airport;
ii fly;
int n,k,i,ti[N+5],t[N+5];
long long tot_cost;
int main()
{
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++) scanf("%d",&t[i]);
	for(i=1;i<=n||(!airport.empty());i++)
	{
		if(i<=n) airport.push(ii(t[i],i));
		if(i>k)
		{
			fly=airport.top();
			airport.pop();
			tot_cost+=(long long)fly.first*(i-fly.second);
			ti[fly.second]=i;
		}
	}
	for(printf("%lld\n",tot_cost),i=1;i<=n;i++) printf("%d ",ti[i]);
	return 0;
}