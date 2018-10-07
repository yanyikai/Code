#include<cstdio>
#define N 1000001
int a[N],b[10][N],q,i,j,k;
main()
{
	for(i=1;i<N;++i)if(i<10)a[i]=i;
	else{for(j=i,k=1;j;j/=10)if(j%10)k*=j%10;a[i]=a[k];}
	for(i=1;i<10;++i)for(j=1;j<N;++j)b[i][j]=b[i][j-1]+(a[j]==i);
	for(scanf("%d",&q);q--;printf("%d\n",b[k][j]-b[k][i-1]))scanf("%d%d%d",&i,&j,&k);
}
