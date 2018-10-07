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
int n,k,a,b,i;
char Max='G',Min='B',s[100005];
int main()
{
	scanf("%d%d%d%d",&n,&k,&a,&b);
	if(a<b) swap(a,b),swap(Max,Min);
	for(i=1;i<=n;i++) s[i]=Max;
	for(i=k+1;i<=n;i+=k+1)
	{
		if(!b) return 0*puts("NO");
		s[i]=Min,b--;
	}
	for(i=1;i<=n&&b;i++) if(s[i]!=Min&&!(i>1&&s[i-1]==Min)&&!(i<n&&s[i+1]==Min)) s[i]=Min,b--;
	return 0*printf("%s",s+1);
}