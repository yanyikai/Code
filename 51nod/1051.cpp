#include<cstdio>
#define N 505
#define int long long 
inline int read(){
    int x=0,f=0;
    char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int a[N][N];
signed main()
{
    int m=read(),n=read(),ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read()+a[i-1][j];
    for(int l=1;l<=n;++l)
        for(int r=l;r<=n;++r)
        {
            int cnt=0;
            for(int j=1;j<=m;++j)
            {
                cnt+=a[r][j]-a[l-1][j];
                if(cnt<0)cnt=0;
                if(cnt>ans)ans=cnt;
            }
        }
    printf("%lld\n",ans);
    return 0;
}