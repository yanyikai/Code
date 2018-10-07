#include<cstdio>
#include<cstring>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int m[1000005];
int main()
{
    for(int n;~scanf("%d",&n);)
    {
        memset(m,0,sizeof m);
        int ans=0;
        for(int i=0;i<n;++i)
            ++m[read()];
        for(int i=1;i<1000001;++i)
        {
            ans+=m[i]>>1;m[i]&=1;
            if(i<999999&&m[i]&&m[i+1]&1&&m[i+2])
            ++ans,--m[i],--m[i+1],--m[i+2];
        }printf("%d\n",ans);
    }
    return 0;
}
