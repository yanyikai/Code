#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[55],sum;
double f[55][55],ans,res[55];
int main()
{
    int n,m;scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i),sum+=a[i];
    for(int k=1;k<=m;++k)
    {
        memset(f,0,sizeof f);**f=1;
        for(int i=0;i<n;++i)
            for(int j=0;j<=m;++j){
                double tmp=1;
                for(int p=0;p<=min(a[i+1]*k,m-j);tmp*=1.0*(j+p+1)/(p+1)/n,++p)
                    f[i+1][j+p]+=f[i][j]*tmp;
            }
        res[k]=f[n][m];
    }
    for(int i=m;i;--i)
        ans+=i*(res[i]-res[i-1]);
    printf("%.15lf\n",ans);
    return 0;
}