#include<bits/stdc++.h>
#define MOD 1000000007
#define L long long
using namespace std;
L cnt,num[12],d[12],dp[12][12],ans,n;  
void DFS(L now,L ma,L pos,L nu)
{  
    if(now>=ma) return;
    if(pos==7)
    {  
        ans=(ans+nu)%MOD;  
        return;
    }  
    for(L i=0;i<cnt;i++)  
    {  
        if(!d[i]) continue;d[i]--;
        DFS(now+i,ma,pos+1,nu*(d[i]+1)%MOD);d[i]++;
    }
} 
L dfs(L p,L res,bool lim) 
{
    if(!p) return res==0;  
    if((!lim)&&dp[p][res]!=-1) return dp[p][res];
    L maxn=lim?num[p]:9,ans=0;
    for(L i=0;i<=maxn;i++) ans+=dfs(p-1,res-(i==4||i==7),lim&&i==num[p]);  
    return lim?ans:dp[p][res]=ans;  
}  
int main()  
{  
    memset(dp,-1,sizeof(dp));  
    for(scanf("%I64d",&n);n;n/=10) num[++cnt]=n%10;
    for(L i=0;i<=cnt;i++) d[i]=dfs(cnt,i,1);d[0]--;
    for(L i=1;i<=cnt;i++) DFS(0,i,1,d[i]);
    printf("%I64d\n",ans);  
}  
