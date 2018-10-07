#include<bits/stdc++.h>
#define L long long
using namespace std;
int mod=1e9+7;
L d[2002],a[2002],cnt,t,n,x,y;
L C(int p)
{
	L ans=1;
    for(int i=2;i<=p;i++) ans=(ans*i)%mod;
    return ans;
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==-1) cnt++;
    }
    for(int i=1;i<=n;i++) if(a[i]>0) if(a[a[i]]==-1) t++;
    x=t,y=cnt-t;
    d[0]=C(x);
    for(int i=1;i<=y;i++)
    {
        d[i]=((x+i-1)*d[i-1])%mod;
        if(i>1) d[i]=(d[i]+(i-1)*d[i-2])%mod;
    }
    printf("%lld\n",d[y]);
    return 0;
}