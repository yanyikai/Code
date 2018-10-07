#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
  
using namespace std;  
  
long long int n,m,b;  
long long int dp[ (1<<20)+10 ];  
  
struct FD  
{  
    long long int x,k,pb;  
}fd[120];  
  
bool cmp(FD a,FD b)  
{  
    return a.k<b.k;  
}  
  
int main()  
{  
    scanf("%d%d%d",&n,&m,&b);  
    for(int i=0;i<n;i++)  
    {  
        long long int xi,ki,mi,problem=0;  
        cin>>xi>>ki>>mi;  
        for(int j=0;j<mi;j++)  
        {  
            int a;  
            scanf("%d",&a);  
            a--;  
            problem|=(1<<a);  
        }  
        fd[i]=(FD){xi,ki,problem};  
    }  
    sort(fd,fd+n,cmp);  
    int state=(1<<m)-1;  
    for(int i=0;i<=state;i++) dp[i]=(long long int )(1LL<<60);  
    dp[0]=0;  
    long long int ans=(long long int )(1LL<<60);  
    for(int i=0;i<n;i++)  
    {  
        for(int j=0;j<=state;j++)  
        {  
            dp[j|fd[i].pb]=min(dp[j|fd[i].pb],dp[j]+fd[i].x);  
        }  
        ans=min(ans,dp[state]+fd[i].k*b);  
    }  
    if(ans==(long long int )(1LL<<60)) ans=-1;  
    cout<<ans<<endl;  
    return 0;  
}  
