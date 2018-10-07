// #pragma GCC diagnostic error "-std=c++11"
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
struct P{
    int x,y;
}a;
int main()
{
    for(long long x,y;~scanf("%lld%lld",&x,&y);)
    {
        a=P{x,y};
        printf("%lld\n",x+y);
    }
    return 0;
}
