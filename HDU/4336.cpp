#include<bits/stdc++.h>
using namespace std;
double p[22],ans,sum;
int n,i,j,cnt;
int main()
{
    while(~scanf("%d", &n))
    {
        for(i=0;i<n;i++) scanf("%lf",&p[i]);ans=0;
        for(i=1;i<(1<<n);i++)
        {
            cnt=0;sum=0;
            for(j=0;j<n;j++) if(i&(1<<j)) sum+=p[j],cnt++;
            ans+=cnt&1?1.0/sum:-1.0/sum;
        }
        printf("%lf\n", ans);
    }
    return 0;
}
