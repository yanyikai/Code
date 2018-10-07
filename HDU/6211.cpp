#include<cstdio>
#include<iostream>
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
int res[1<<17],a[1<<17];
void get(int a,int b,int c)
{
    if(c>1e9)return ;
    ++res[max(a,b)&((1<<17)-1)];
    int ma=a<<1,mb=b<<1,mc=c<<1;
    get(a-mb+mc,ma-b+mc,ma-mb+mc+c);
    get(a+mb+mc,ma+b+mc,ma+mb+mc+c);
    get(mb+mc-a,b+mc-ma,mb+mc+c-ma);
}
signed main()
{
    get(3,4,5);
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int k=read(),ans=0;
        for(int i=0;i<1<<k;++i)
            a[i]=read();
        for(int i=0;i<1<<17;++i)
            ans+=res[i]*a[i&((1<<k)-1)];
        printf("%lld\n",ans);
    }
    return 0;
}
