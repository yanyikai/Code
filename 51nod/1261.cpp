#include<cstdio>
#include<cstring>
#define K 505
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int r[K],cnt[K],f[K][10],inv[10],P=1e9+7;
signed main()
{
    int n=read(),m=read(),p=0,a,b,x=1,ans=0;
    for(;!cnt[x];x=(x*10+1)%m)cnt[x]=++p,r[p]=x;
    r[++p]=x;a=cnt[x];b=p-a;p=n<a?r[n]:r[a+(n-a)%b];
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<a&&i<=n;++i)++cnt[r[i]];
    for(int i=0;i<b&&i+a<=n;++i)
        cnt[r[a+i]]=(cnt[r[a+i]]+(n-a-i)/b+1)%P;
    if(--cnt[p]<0)cnt[p]+=P;
    // for(int i=0;i<m;++i)printf("%lld ",cnt[i]);puts("");
    inv[1]=**f=1;
    for(int i=2;i<10;++i)inv[i]=P-P/i*inv[P%i]%P;
    for(int i=0;i<m;++i)if(cnt[i])
        for(int j=9;j;--j)
            for(int k=1,mul=1;k<=j&&mul;++k)
            {
                mul=mul*(cnt[i]-1+k)%P*inv[k]%P;
                for(int o=0;o<m;++o)
                    (f[(o+k*i)%m][j]+=mul*f[o][j-k]%P)%=P;
            }
    for(int i=1;i<10;++i)
        for(int j=0;i+j<10;++j)
            (ans+=f[(m-p*i%m)%m][j])%=P;
    printf("%lld\n",(ans%P+P)%P);
    return 0;
}