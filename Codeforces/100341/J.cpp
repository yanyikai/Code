#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=305;
const LL inf=0x3f3f3f3f3f3f3f3f;

int n,m;
LL f[N][N],dis[N][N];

int main() {
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	cin>>n>>m;
	memset(f,0x3f,sizeof(f));
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=m;i++) {
		LL u,v,l; cin>>u>>v>>l;
		dis[u][v]=min(dis[u][v],l);
		dis[v][u]=min(dis[v][u],l);
		f[u][v]=f[v][u]=1;
	}
	for (int i=1;i<=n;i++) dis[i][i]=f[i][i]=0;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				if (dis[i][j]>dis[i][k]+dis[k][j]) {
					dis[i][j]=dis[i][k]+dis[k][j];
					f[i][j]=f[i][k]+f[k][j];
				}
				else if (dis[i][j]==dis[i][k]+dis[k][j]) {
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
	LL sum1=0,sum2=(n-1)*n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j) sum1+=f[i][j];
	printf("%.8f",1.0*sum1/sum2);
	return 0;

}
