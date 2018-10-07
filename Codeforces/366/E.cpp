#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,a,p,q,ans;
int maxn[10][2],minn[10][2]; 
inline int maxx(int a,int b,int c,int d,int e)  
{  
    return max(a,max(max(b,c),max(d,e)));  
}
int main()  
{  
    memset(maxn,192,sizeof(maxn));  
    memset(minn,63,sizeof(minn));  
    scanf("%d%d%d%d",&n,&m,&k,&s);  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=m;j++)  
        {    
            scanf("%d",&a);  
            maxn[a][0]=max(maxn[a][0],i+j);maxn[a][1]=max(maxn[a][1],i-j);  
            minn[a][0]=min(minn[a][0],i+j);minn[a][1]=min(minn[a][1],i-j);  
        }  
    }
    for(int i=0;i<s;i++,p=q)  
    {  
        scanf("%d",&q);  
        if(i) ans=maxx(ans,maxn[p][0]-minn[q][0],maxn[q][1]-minn[p][1],maxn[p][1]-minn[q][1],maxn[q][0]-minn[p][0]);  
    }  
    printf("%d\n",ans);  
    return 0;  
}