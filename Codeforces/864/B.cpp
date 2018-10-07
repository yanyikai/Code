#include<bits/stdc++.h>
#define F1(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define pi        acos(-1.0)
#define L         long long
#define E         long double
#define D         double
#define P         pair<int,int>
#define st        first
#define nd        second
#define pb        push_back
#define mp        make_pair
#define INFI      0x3f3f3f3f
#define INFL      0x7f7f7f7f
#define MOD       1000000007
#define N         
#define M         
#define MS(n,v)   memset(n,v,sizeof(n));
//#define int       long long
//#define %d        %I64d
//#define Debug
//#define File
using namespace std;
char c[10001];
map<char,int> m;
int n,i,ans=0,l;
bool p=false;
int main()
{
	#ifdef File
		freopen("B.in","r",stdin);
		freopen("B.out","w",stdout);
	#endif
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%c",&c[i]);
		if(c[i]>='a'&&c[i]<='z') m[c[i]]++;
		else
		{
			ans=max(ans,l=m.size());
			m.clear();
		}
	}
	ans=max(ans,l=m.size());
	printf("%d",ans);
	return 0;
}
