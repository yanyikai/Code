#include<cstdio>
#include<cstring>
#define N 1048576
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N],m[N];
int main()
{
    for(int n;~scanf("%d",&n);)
    {
        int ans=0,p=1e9+7;
        for(int i=0;i<n;++i)++m[a[i]=read()];
        for(int p=0;p<20;++p)
            for(int i=1;i<N;++i)
                if(~i>>p&1)
                    m[i|(1<<p)]+=m[i];
        for(int i=0;i<n;++i)
            (ans+=((1<<20)-1)&a[i])%=p;
        printf("%d\n",ans);
        memset(m,0,sizeof m);
    }
    return 0;
}