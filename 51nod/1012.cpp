#include<cstdio>
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int main()
{
    int a=read(),b=read();
    long long x=1ll*a*b;
    for(;b;a^=b^=a^=b)a%=b;
    printf("%lld\n",x/a);
    return 0;
}