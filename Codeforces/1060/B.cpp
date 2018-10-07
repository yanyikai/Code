#include<cstdio>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int get(int x){
    int res=0;
    for(;x;x/=10)res+=x%10;
    return res;
}
signed main()
{
    int n=read(),b=0;
    for(;b*10+9<=n;)b=b*10+9;
    printf("%lld\n",get(n-b)+get(b));
    return 0;
}
