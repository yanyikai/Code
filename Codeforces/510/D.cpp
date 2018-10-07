#include<bits/stdc++.h>
using namespace std;
int l[305],c[305];
map<int,int>m;
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",l+i);
	for(int i=0;i<n;++i)scanf("%d",c+i);
	m[0]=0;
	for(int i=0;i<n;++i)
		for(auto v:m)
		{
			int t=__gcd(v.first,l[i]);
			if(m.count(t))
				m[t]=min(m[t],v.second+c[i]);
			else
				m[t]=v.second+c[i];
		}
	!m[1]?puts("-1"):printf("%d",m[1]);
	return 0;
}
