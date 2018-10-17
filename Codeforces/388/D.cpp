#include<cstdio>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int f[32][32][2],p=1e9+7;
void U(int&a,int b){if((a+=b)>=p)a-=p;}
signed main()
{
    int n=read();f[30][0][1]=1;
    for(int i=29;~i;--i)
        for(int j=0;j<=30;++j)
        {
            U(f[i][j+1][0],f[i+1][j][0]);
            U(f[i][j][0],(1<<j)*f[i+1][j][0]%p);
            if(n>>i&1)
                U(f[i][j][1],(j?(1<<j-1):0)*f[i+1][j][1]%p),
                U(f[i][j][0],(j?(1<<j-1):1)*f[i+1][j][1]%p),
                U(f[i][j+1][1],f[i+1][j][1]);
            else U(f[i][j][1],(j?(1<<j-1):1)*f[i+1][j][1]%p);
        }
    int ans=0;
    for(int i=0;i<=30;++i)
        U(ans,(f[0][i][0]+f[0][i][1])%p);
    printf("%lld\n",ans);
    return 0;
}