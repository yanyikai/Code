#pragma GCC optimize(3,"inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10000005
inline int R(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int a[N],Q[N],sum[N];
int main()
{
    for(int cas=0,T=R();cas<T;++cas)
    {
        int n=R(),m=R(),k=R(),be=1,en=0;
        int p=R(),q=R(),r=R(),mod=R();
        long long ans=0;
        for(int i=1;i<=k;++i)scanf("%d",a+i),sum[i]=0;
        for(int i=k+1;i<=n;++i)a[i]=(1ll*p*a[i-1]+1ll*q*i+r)%mod,sum[i]=0;
        for(int i=1;i<m;Q[++en]=i++)
            for(;en&&a[i]>=a[Q[en]];--en);
        for(int i=m;i<=n;++i)
        {
            if(Q[be]+m<i+1)++be;
            for(;be<=en&&a[i]>=a[Q[en]];--en);
            Q[++en]=i;ans+=a[Q[be]]^(i-m+1);
        }printf("%lld ",ans);ans=en=0;
        for(int i=1;i<=n;++i)
        {
            for(;en&&a[i]>a[Q[en]];--en);
            ++sum[max(i-m,Q[en])+1];Q[++en]=i;--sum[i+1];
        }
        for(int i=1;i+m<=n+1;++i)
            sum[i]+=sum[i-1],ans+=sum[i]^i;
        printf("%lld\n",ans);
    }
    return 0;
}
