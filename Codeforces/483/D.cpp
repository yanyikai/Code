#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100005
#define P pair<int,int>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
vector<P>num[30];
int a[30][N],l[N],r[N],q[N],n,m;
inline int check()
{
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<30;++j)
		{
			if(q[i]&1<<j)continue;
			if(a[j][r[i]]-a[j][l[i]-1]==r[i]-l[i]+1)return 1;
		}
	}
	return 0;
}
int main()
{
	n=read(),m=read();
	for(int i=0;i<m;++i)
	{
		l[i]=read(),r[i]=read(),q[i]=read();int t=q[i];
		for(int j=0;t;t>>=1,++j)if(t&1)
		num[j].push_back(P(l[i],1)),num[j].push_back(P(r[i]+1,-1));
	}for(int i=0;i<30;++i)
	{
		sort(num[i].begin(),num[i].end());
		int now=0;vector<P>::iterator it=num[i].begin();
		for(int j=1;j<=n;++j)
		{
			for(;it!=num[i].end()&&it->first==j;++it)now+=it->second;
			a[i][j]=a[i][j-1]+(now>0);
		}
	}
	if(check())puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<30;++i)
		for(int j=n;j;--j)
		a[i][j]-=a[i][j-1];
		for(int j=1;j<=n;++j)
		{
			int x=0;
			for(int i=0;i<30;++i)
			if(a[i][j])x+=1<<i;
			printf("%d ",x);
		}
	}
	return 0;
}
