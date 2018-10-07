#include<cstdio>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int main()
{
    for(int cas=0,T=read();cas<T;++cas)
    {
        int n=read();
        if(n%3==0)printf("%lld\n",1ll*n*n*n/27);else
        if(n%4==0)printf("%lld\n",1ll*n*n*n/32);else
        puts("-1");
    }
    return 0;
}
