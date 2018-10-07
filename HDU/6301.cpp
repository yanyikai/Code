#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
// inline int read(){
//     int x=0,f=0;
//     register char ch=getchar();
//     for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
//     for(;ch>47&&ch<58;ch=getchar())
//     x=(x<<1)+(x<<3)+(ch^48);
//     return f?~x+1:x;
// }
using namespace std;
struct P{
    int l,r;
    bool operator<(const P&o)const{
        return l==o.l?r>o.r:l<o.l;
    }
}a[N];
int res[N];
set<int>s;
int main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        s.clear();
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i)
            scanf("%d%d",&a[i].l,&a[i].r);
        sort(a+1,a+m+1);
        for(int i=1;i<=n;++i)
            res[i]=0,s.insert(i);
        for(int i=1;i<=m;++i)
        {
            for(int j=a[i-1].l;j<a[i].l;++j)
                if(res[j])s.insert(res[j]);
            for(int j=max(a[i].l,a[i-1].r+1);j<=a[i].r;++j)
                if(!res[j])res[j]=*s.begin(),s.erase(s.begin());
        }
        for(int i=1;i<=n;++i)
            printf("%d%c",res[i]?res[i]:1,i==n?'\n':' ');
    }
    return 0;
}
