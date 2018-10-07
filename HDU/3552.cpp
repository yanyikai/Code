#include<cstdio>
#include<algorithm>
using namespace std;
struct P{
    int x,y;
    bool operator<(const P&o)const{
        return x>o.x;
    }
}a[100005];
int main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d%d",&a[i].x,&a[i].y);
        sort(a+1,a+n+1);
        int mxn=a[1].y,ans=a[1].x;
        for(int i=2;i<=n;++i)
        {
            ans=min(ans,mxn+a[i].x);
            mxn=max(mxn,a[i].y);
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
