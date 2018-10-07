#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x; 
}
using namespace std;
int a[20],sta[3000],tot;
double s[3000],dp[1<<14];
inline double S(int i,int j,int k)
{
    double p=(a[i]+a[j]+a[k])*0.5;
    return sqrt(p*(p-a[i])*(p-a[j])*(p-a[k]));
}
int main()
{
    for(int n;~scanf("%d",&n)&&n;)
    {
        tot=0;
        for(int i=0;i<n;++i)
        a[i]=read();sort(a,a+n);
        for(int i=0;i+2<n;++i)
        for(int j=i+1;j+1<n;++j)
        for(int k=j+1;k<n;++k)
        if(a[j]-a[i]<a[k]&&a[k]<a[i]+a[j])
        s[++tot]=S(i,j,k),sta[tot]=(1<<i)|(1<<j)|(1<<k);
        memset(dp,0,sizeof dp);
        for(int i=0;i<1<<n;++i)
        for(int j=1;j<=tot;++j)
        if((i&sta[j])==0)
        dp[i|sta[j]]=max(dp[i|sta[j]],dp[i]+s[j]);
        double ans=0;
        for(int i=0;i<1<<n;++i)
        ans=max(ans,dp[i]);
        printf("%.2lf\n",ans);
    }
    return 0;
}
