#include<cstdio>
#include<cmath>
#define  int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int ans=0;
inline int phi(int x)
{
    int m=sqrt(x),res=x;
    for(int i=2;i<=m;++i)
        if(x%i==0)
            for(res=res*(i-1)/i;x%i==0;x/=i);
    return x^1?res*(x-1)/x:res;
}
signed main()
{
    int n=read(),m=sqrt(n);
    for(int i=1;i<=m;++i)
        if(n%i==0)
        {
            ans+=i*phi(n/i);
            if(n/i!=i)
                ans+=(n/i)*phi(i);
        }
    printf("%lld\n",ans);
    return 0;
}