#include<bits/stdc++.h>
#define MOD 1000000007
#define L long long
#define F(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
struct matrix
{
	int a[110][110];
}A,B,C;
L a[1000],x,m,n,cnt,ans;
matrix operator * (matrix A,matrix B)
{
	matrix C;
	F(i,1,n) F(j,1,n) C.a[i][j]=0;
	F(k,1,n) F(i,1,n) F(j,1,n) C.a[i][j]=(L)(C.a[i][j]+(L)A.a[i][k]*B.a[k][j]%MOD)%MOD;
	return C;
}
int main()
{
	scanf("%d%I64d",&n,&m);
	F(i,1,n) scanf("%I64d",&a[i]);
	F(i,1,n) F(j,1,n)
	{
		cnt=0;
		x=a[i]^a[j];
		while(x) cnt+=x&1,x>>=1;
		if(cnt%3==0) A.a[i][j]=1;
	}m--;
	F(i,1,n) B.a[i][i]=1;
	for(;m;m>>=1,A=A*A) if(m&1) B=B*A;
	F(i,1,n) F(j,1,n) ans=(ans+B.a[i][j])%MOD;
	printf("%d",ans);
	return 0;
}