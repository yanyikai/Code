#pragma GCC optimize(3,"inline,Ofast")
#include<cstdio>
#include<bitset>
#define P pair<int,int>
const int N=2e3+5,p=1e9+7;
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
bitset<4000005>vis(1);
signed main()
{
    int n=read(),sum=0;
    for(int i=1,x;i<=n;++i)
        sum+=x=read(),vis|=vis<<x;
    for(int i=sum/2;~i;--i)
        if(vis[i])
            return printf("%d\n",sum-i),0;
    return 0;
}