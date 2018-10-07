#include<bits/stdc++.h>
using namespace std;
int t[300005],sum[300005],l,r,mid,n,k,ans,beg,end;
int main()
{
    scanf("%d%d",&n,&k);  
    for(int i=1;i<=n;i++) scanf("%d",&t[i]),sum[i]=sum[i-1]+t[i];
    for(int i=1;i<=n;i++)
	{  
        l=i,r=n;
        while(l<=r)
		{
            mid=(l+r)>>1;  
            if(mid-i+1<=k+sum[mid]-sum[i-1]) l=mid+1;
            else r=mid-1;
        }
        if(r-i+1>ans) ans=r-i+1,beg=i,end=r;
    }
    printf("%d\n", ans);
    for(int i=beg;i<=end;i++) t[i]=1;
    for(int i=1;i<=n;i++) printf("%d ",t[i]);
    return 0;
}