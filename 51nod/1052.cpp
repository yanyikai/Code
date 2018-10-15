#include<cstdio>
#define N 50005
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N];
signed main()
{
    int n=read(),m=read(),cnt=0;
    for(int i=1;i<=n;++i)
        a[i]=read(),cnt+=(a[i]>0);
    
    return 0;
}