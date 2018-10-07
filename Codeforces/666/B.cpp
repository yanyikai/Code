#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 3005
vector<int>fir[N];
int h[N],en,d[N][N],q[N],qn,a[N][N],b[N][N],X,aa,bb,cc,dd,ans;
bool cmp1(int x,int y){return d[X][x]>d[X][y];}
bool cmp2(int x,int y){return d[x][X]>d[y][X];}
void rw(int A,int B,int C,int D)
{
	if(d[A][B]&&d[B][C]&&d[C][D]&&d[A][B]+d[B][C]+d[C][D]>ans)
		ans=d[aa=A][bb=B]+d[B][C]+d[cc=C][dd=D]; 
}
int main()
{
	int n,m,i,j,k,l;
	scanf("%d%d",&n,&m);
	for(;m--;)
		scanf("%d%d",&i,&j),
		fir[i].push_back(j);
	for(i=1;i<=n;++i)
		for(d[i][q[j=qn=1]=i]=1;j<=qn;++j)
			for(int k:fir[q[j]])
				if(!d[i][k])d[i][q[++qn]=k]=d[i][q[j]]+1;
	for(i=1;i<=n;++i)
	{
		for(X=i,j=1;j<=n;++j)a[i][j]=b[i][j]=j;
		sort(a[i]+1,a[i]+n+1,cmp1);
		sort(b[i]+1,b[i]+n+1,cmp2);
	}
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(i!=j)
		for(k=1;k<=3;++k)if(b[i][k]!=i&&b[i][k]!=j)
			for(l=1;l<=3;++l)if(a[j][l]!=i&&a[j][l]!=j&&a[j][l]!=b[i][k])
				rw(b[i][k],i,j,a[j][l]);
	printf("%d %d %d %d",aa,bb,cc,dd);
}
