#include<cstdio>
#define N 99
#define int long long
#define F(_) for(int _=0;_<L;++_)
using namespace std;
int a[15],L,sum;
int m[N][N],sumr[N],sumc[N];
long long get(int x,int y)
{
    long long res=0;
    int l=x/L,r=y/L;res+=1ll*l*r*sum;
    if(x%L)res+=1ll*sumr[x%L-1]*r;
    if(y%L)res+=1ll*sumc[y%L-1]*l;
    l=x%L,r=y%L;
    for(int i=0;i<l;++i)
        for(int j=0;j<r;++j)
            res+=m[i][j];
    return res;
}
main()
{
    int T;scanf("%lld",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%lld",&L);
        F(i)scanf("%lld",a+i);
        int p=0;
        for(int i=0;i<4*L;++i)
            for(int j=0;j<=i;++j)
                m[j][i-j]=a[p],p=(p+1)%L;
        sum=0;L*=2;
        F(i)sumr[i]=sumc[i]=0;
        F(i)F(j)sum+=m[i][j];
        F(i)
        {
            F(j)sumr[i]+=m[i][j];
            if(i)sumr[i]+=sumr[i-1];
        }
        F(j)
        {
            F(i)sumc[j]+=m[i][j];
            if(j)sumc[j]+=sumc[j-1];
        }
        int q;scanf("%lld",&q);
        for(;q--;)
        {
            int x0,y0,x1,y1;
            scanf("%lld%lld%lld%lld",&x0,&y0,&x1,&y1);
            printf("%lld\n",get(x1+1,y1+1)+get(x0,y0)-get(x1+1,y0)-get(x0,y1+1));
        }
    }
    return 0;
}
