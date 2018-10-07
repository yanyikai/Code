#include<cstdio>
#include<map>
#include<set>
#define P pair<int,int>
using namespace std;
set<P>s;map<int,int>m;
int main()
{
	int n,q;scanf("%d%d",&n,&q);
	s.insert(P(0,1));
	s.insert(P(n+1,0));
	for(int i=0;i<q;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		char c[3];scanf("%s",c);
		if(m.count(x)){puts("0");continue;}
		if(*c=='U')
		{
			P p=*s.lower_bound(P(x,-1));
			m[x]=p.first-x+(p.second==1?m[p.first]:0);
			s.insert(P(x,1));
		}
		else
		{
			set<P>::iterator it=--s.lower_bound(P(x,-1));
			m[x]=x-it->first+(it->second==0?m[it->first]:0);
			s.insert(P(x,0));
		}
		printf("%d\n",m[x]);
	}
	return 0;
}