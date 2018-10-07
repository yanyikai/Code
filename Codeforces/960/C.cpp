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
long long ans[1005];
int main()
{
    int x=read(),d=read(),l=0;
    long long num=1;
    for(;x;)
    {
        for(int i=1;i<=x;i<<=1)
            ans[++l]=num,x-=i;
        num+=d;
    }
    printf("%d\n",l);
    for(int i=1;i<=l;++i)
        printf("%lld ",ans[i]);
    return 0;
}
