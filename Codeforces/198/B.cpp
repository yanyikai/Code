#include<bits/stdc++.h>
#define N 100005
#define P pair<bool,int>
#define lr first
#define x second
#define mp make_pair
using namespace std;
P t;
int n,k,i,tim;char c;
bool wall[N][2];
bool vis[N][2];
queue<P> q;
int main()
{
	scanf("%d%d",&n,&k);
	for(int j=0;j<2;j++) for(getchar(),i=0;i<n;i++) c=getchar(),wall[i][j]=c=='X'?0:1;
	q.push((P){0,0});vis[0][0]=1;
	while(!q.empty())
	{
		for(int l=q.size();l--;)
		{
			t=q.front();q.pop();
			if(t.x+k>=n) return 0*puts("YES");
			if(t.x+k==n-1&&wall[t.x+k][!t.lr]) return 0*puts("YES");
			if(wall[t.x+k][!t.lr]&&!vis[t.x+k][!t.lr])
			{
				if(t.x+k>n-2) return 0*puts("YES"); 
				q.push(mp(!t.lr,t.x+k));
				vis[t.x+k][!t.lr]=1;
			}
			if(wall[t.x+1][t.lr]&&!vis[t.x+1][t.lr])
			{
				if(t.x+1>n-2) return 0*puts("YES");
				q.push(mp(t.lr,t.x+1));
				vis[t.x+1][t.lr]=1;
			}
			if(wall[t.x-1][t.lr]&&t.x-1>tim&&!vis[t.x-1][t.lr])
			{
				q.push(mp(t.lr,t.x-1));
				vis[t.x-1][t.lr]=1;
			}
		}
		if(++tim>n) break;
	}
	return 0*puts("NO");
}