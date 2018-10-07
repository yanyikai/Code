#include<cstdio>
#include<algorithm>
#define N 2005
#define P pair<int,int>
#define int long long
using namespace std;
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
int a[N],b[N],f[N];
signed main()
{
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;++i)
        a[i]=read()+a[i-1];
    for(int i=1;i<=m;++i)
        b[i]=read()+b[i-1];
    int x=read();
    for(int L=n;L;--L)
    {
        int mxn=1e9;
        for(int i=L;i<=n;++i)
            mxn=min(mxn,a[i]-a[i-L]);
        int l=1;
        for(int i=1;i<=m;++i)
        {
            for(;l<=i&&mxn*(b[i]-b[l-1])>x;++l);
            ans=max(ans,L*(i-l+1));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
