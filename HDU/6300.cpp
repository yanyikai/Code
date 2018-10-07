#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
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
    int x,id;
    bool operator<(const P&o)const{
        return x<o.x;
    }
}a[100005];
int main()
{
    for(int cas=0,T=read();cas<T;++cas)
    {
        int n=read();
        for(int i=1,x;i<=n*3;++i)
            x=read(),read(),
            a[i]=P{x,i};
        sort(a+1,a+n*3+1);
        for(int i=1;i<=n*3;i+=3)
            printf("%d %d %d\n",a[i].id,a[i+1].id,a[i+2].id);
    }
    return 0;
}
