#include<bits/stdc++.h>
#define N 
#define M 
#define INF 0x3f3f3f3f
#define P pair<L,L>
#define L long long
#define MEM(n,i) memset(n,i,sizeof(n))
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D double
//#define int long long
//#define %d %lld
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",(min(a,min(b/2,c/4)))*7);
	return 0;
}