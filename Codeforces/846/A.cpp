#include<bits/stdc++.h>
using namespace std;
int a[105],i,j,n,ans=1,ans_;
int main()
{
    for(scanf("%d",&n),i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        ans_=0;
        for(j=0;j<=i;j++) if(a[j]==0) ans_++;
        for(j=i;j<n;j++) if(a[j]==1) ans_++;
        ans=max(ans,ans_);
    }
    printf("%d",ans);
    return 0;
}