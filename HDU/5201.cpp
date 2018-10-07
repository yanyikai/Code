#include<cstdio>
#define int long long
#define L long long
const int p=1e9+7,N=1e5+5;
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
        x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int pow[N<<1]={1},inv[N<<1]={1};
inline L Pow(L x,L y=p-2){L res=1;for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;return res;}
inline int C(int x,int y){return pow[x]*inv[y]%p*inv[x-y]%p;}
inline int get(int x,int n,int m)
{
    if(!n) return 1;
    int ans=0;
    for(int i=0;i<=m&&i*x<=n;++i)
    {
        int t=C(m,i)*C(n-i*x+m-1,m-1)%p;
        ans=i&1?(ans-t+p)%p:(ans+t)%p;
    }
    return ans;
}
signed main()
{
    for(int i=1;i<N<<1;++i)inv[i]=Pow(pow[i]=pow[i-1]*i%p,p-2);
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int n=read(),m=read();
        if(m==1)
        {
            puts("1");
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;++i)
            ans=(ans+get(i,n-i,m-1))%p;
        printf("%lld\n",ans);
    }
    return 0;
}
