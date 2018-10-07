#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int fac[500],num[500],vis[500];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int ans=0,tot=0;
        memset(num,0,sizeof num);
        memset(vis,0,sizeof vis);
        int n=read(),m=read();
        for(int i=1;i*i<=m;++i)
        if(i*i==m)fac[++tot]=i;
        else if(m%i==0)fac[++tot]=i,fac[++tot]=m/i;
        sort(fac+1,fac+tot+1);
        for(int i=0;i<n;++i)
        {
            int t=gcd(read(),m);
            for(int j=1;j<=tot;++j)
            if(fac[j]%t==0)vis[j]=1;
        }vis[tot]=0;
        for(int i=1;i<=tot;++i)
        {
            if(vis[i]!=num[i])
            {
                int t=m/fac[i];
                ans+=t*(t-1)/2*fac[i]*(vis[i]-num[i]);
                t=vis[i]-num[i];
                for(int j=i;j<=tot;++j)
                if(fac[j]%fac[i]==0)num[j]+=t;
            }
        }
        printf ("Case #%lld: %lld\n",cas,ans);
    }
    return 0;
}
