#include<bits/stdc++.h>
#define N 705
int n,s[N],g[N][N],L[N][N],R[N][N],f[N][N];
main(){
	for(int i=0;i<=(n=*s);++i)scanf("%d",s+i);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)g[i][j]=std::__gcd(s[i],s[j])>1;
	for(int i=1;i<=n;++i)L[i][i]=R[i][i]=1;
	for(int i=1;i<=n;++i)for(int j=i;j;--j)for(int k=j;k<=i;++k)
		if(L[j][k]&&R[k][i])f[j][i]|=1,R[j-1][i]|=g[k][j-1],L[j][i+1]|=g[k][i+1];
	puts(f[1][n]?"Yes":"No");
}
