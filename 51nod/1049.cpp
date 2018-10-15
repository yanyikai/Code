#include<cstdio>
#define int long long
inline int read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
signed main()
{
    int n=read(),ans=0,cnt=0;
    for(int i=0;i<n;++i)
    {
        cnt+=read();
        if(cnt<0)cnt=0;
        if(cnt>ans)ans=cnt;
    }
    printf("%lld\n",ans);
    return 0;
}