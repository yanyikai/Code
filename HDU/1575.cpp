#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=9973;
int n,T,ans,k;
struct JZ { int v[15][15]; }A,B,C;
JZ operator * (JZ A,JZ B)
{
	memset(C.v,0,sizeof C.v);
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	C.v[i][j]=(C.v[i][j]+(A.v[i][k]*B.v[k][j])%MOD)%MOD;
	return C;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(A.v,0,sizeof A.v);
		scanf("%d%d",&n,&k);k--;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		scanf("%d",&A.v[i][j]);
		B=A;
		for(;k;k>>=1,B=B*B) if(k&1) A=A*B;
		for(int i=0;i<n;i++) ans=(ans+A.v[i][i])%MOD;
		printf("%d\n",ans);
	}
	return 0;
}
