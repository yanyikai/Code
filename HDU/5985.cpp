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
int num[20];
double p[20],a[20][150],b[20][150];
inline double Pow(double x,int y)
{
    double res=1.0;
    for(;y;y>>=1,x*=x)if(y&1)res*=x;
    return res;
}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int n=read();
        for(int i=0;i<n;++i)
            num[i]=read(),scanf("%lf",p+i);
        if(n==1)
        {
            puts("1.000000");
            continue;
        }
        for(int i=0;i<n;++i)
            for(int j=1;j<150;++j)
            {
                a[i][j]=Pow((1-Pow(p[i],j)),num[i]);
                b[i][j]=1-a[i][j];
            }
        for(int i=0;i<n;++i)
        {
            double ans=0;
            for(int k=1;k<149;++k)
            {
                double t=1.0;
                for(int j=0;j<n;++j)
                if(i!=j)t*=a[j][k];
                ans+=(b[i][k]-b[i][k+1])*t;
            }
            printf("%.6lf%c",ans,i+1==n?'\n':' ');
        }
    }
    return 0;
}
