#pragma GCC optimize("inline,Ofast")
#include<bits/stdc++.h>
#define N 200005
#define P pair<int,int>
#define int long long
using namespace std;
P a[N];int res[N],tot=1;
set<P>s;
signed main()
{
    int n,m,d;scanf("%lld%lld%lld",&n,&m,&d);
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i].first),a[i].second=i;
    sort(a,a+n);res[a[0].second]=1;
    s.insert(P(a[0].first,1));
    for(int i=1;i<n;++i)
    {
        set<P>::iterator it=s.lower_bound(P(a[i].first-d,0));
        if(it==s.begin()){++tot,res[a[i].second]=tot;s.insert(P(a[i].first,tot));}
        else
        {
            --it;
            int id=it->second;
            res[a[i].second]=id;
            s.erase(it);s.insert(P(a[i].first,id));
        }
    }
    printf("%lld\n",tot);
    for(int i=0;i<n;++i)
        printf("%lld ",res[i]);
	return 0;
}
