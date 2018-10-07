#include<cstdio>
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
int n,a;
inline int Pow(int x,int y,int p)
{
    int ans=1;
    for(;y;y>>=1,x=x*x%p)if(y&1)ans=ans*x%p;
    return ans;
}
inline int get()
{
    if(a&1)return 1;
    int m=1<<n,res=0,t=1<<((n+a-1)/a);
    for(int i=1;i<=n;++i)
        if(Pow(a,i,m)==Pow(i,a,m))
            ++res;
    return res+m/t-n/t;
}
signed main()
{
    for(;~scanf("%lld%lld",&n,&a);)
        printf("%lld\n",get());
    return 0;
}
