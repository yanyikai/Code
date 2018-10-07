#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+100;
ll p[maxn],sum[2*maxn],last[2*maxn];
int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
int main()
{
    int t,n,m,k,i,j,M,now,l,r,len,manys=1;
    ll s,cnt,Ans,ans,temp;
    scanf("%d",&t);
    while(t--)
    {
        Ans=-1e18;
        scanf("%d%lld%d%d",&n,&s,&m,&k);
        for(i=1;i<=n;i++) scanf("%lld",&p[i]);
        cnt=gcd(k,n); len=n/cnt;
        for(i=1;i<=cnt;i++)
        {
            now=i,ans=0;
            for(j=1;j<=2*len;j++,now=(now+k-1)%n+1)
            sum[j]=sum[j-1]+p[now];
            last[1]=1,l=r=1,M=m;
            if(sum[len]>=0) ans+=sum[len]*(M/len),M%=len;
            else M=min(M,len);
            for(j=1;j<=2*len;j++)
            {
                while(l<=r&&last[l]<j-M) l++;
                if(l<=r)
                    temp=ans+sum[j]-sum[last[l]],Ans=max(Ans,temp);
                while(l<=r&&sum[last[r]]>=sum[j]) r--;
                last[++r]=j;
            }
            if(m>=len)
            {
                M=m-len,ans=0;
                if(sum[len]>=0) ans+=sum[len]*(M/len);
                M=len,last[1]=1,l=r=1;
                for(j=1;j<=2*len;j++)
                {
                    while(l<=r&&last[l]<j-M) l++;
                    if(l<=r)
                        temp=ans+sum[j]-sum[last[l]],Ans=max(Ans,temp);
                    while(l<=r&&sum[last[r]]>=sum[j]) r--;
                    last[++r]=j;
                }
            }
        }
        printf("Case #%d: %lld\n",manys++,max(0ll,s-Ans));
    }
    return 0;
}

