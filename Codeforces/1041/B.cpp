#pragma GCC optimize("inline,Ofast")
#include<bits/stdc++.h>
#define N 100005
#define P pair<int,int>
#define int long long
using namespace std;
signed main()
{
    int a,b,x,y;
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    int c=__gcd(x,y);
    x/=c,y/=c;
    printf("%lld\n",min(a/x,b/y));
	return 0;
}
