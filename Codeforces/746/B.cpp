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
int n,i;
char s[100005];
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		scanf("%s",s+1);
		for(i=n-1;i>1;i-=2) printf("%c",s[i]);
		printf("%c",s[1]);
		for(i=3;i<=n;i+=2) printf("%c",s[i]);
	}
	else
	{
		scanf("%s",s+1);
		for(i=n-1;i>0;i-=2) printf("%c",s[i]);
		for(i=2;i<=n;i+=2) printf("%c",s[i]);
	}
	return 0;
}