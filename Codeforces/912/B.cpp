#include<cstdio>
#define int long long
using namespace std;
signed main()
{
    int n,k,sum=1;scanf("%lld%lld",&n,&k);
    if(k==1)return printf("%lld\n",n),0;
    for(;n;n>>=1)sum<<=1;printf("%lld\n",sum-1);
    return 0;
}