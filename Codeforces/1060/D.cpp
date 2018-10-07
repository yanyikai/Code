#include<cstdio>
#include<algorithm>
#define N 100005
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N],b[N],ans;
signed main()
{
    int n=read();
    for(int i=0;i<n;++i)
        a[i]=read(),b[i]=read();
    sort(a,a+n);sort(b,b+n);
    for(int i=0;i<n;++i)
        ans+=max(a[i],b[i]);
    printf("%lld\n",ans+n);
    return 0;
}
