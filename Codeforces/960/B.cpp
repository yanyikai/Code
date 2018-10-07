#include<cstdio>
#include<queue>
#include<cmath>
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
priority_queue<int>Q;
int ans,a[1005];
signed main()
{
    int n=read(),k=read()+read();
    for(int i=0;i<n;++i)a[i]=read();
    for(int i=0;i<n;++i)Q.push(abs(a[i]-read()));
    for(int i=0;i<k;++i)
    {
        int x=Q.top();Q.pop();
        Q.push(abs(--x));
    }
    for(;!Q.empty();)
    {
        int x=Q.top();
        ans+=x*x;
        Q.pop();
    }
    printf("%lld\n",ans);
}
