#include<bits/stdc++.h>
#define N 100005
using namespace std;
int tre[N],a[N],b[N];
map<int,int>m;
int Que(int x)
{
    int res=0;
    for(;x;x-=x&-x)res+=tre[x];
    return res;
}
int main()
{
    for(int n,x,y;~scanf("%d%d%d",&n,&x,&y);)
    {
        memset(tre,0,sizeof tre);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),b[i]=a[i];
        m.clear();sort(b+1,b+n+1);
        int cnt=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=cnt;++i)m[b[i]]=i;
        for(int i=1;i<=n;++i)a[i]=m[a[i]];
        long long ans=0;
        for(int i=1;i<=n;++i)
        {
            ans+=Que(N-1)-Que(a[i]);
            for(int x=a[i];x<N;x+=x&-x)++tre[x];
        }if(x>y)x=y;
        printf("%lld\n",ans*x);
    }
    return 0;
}
