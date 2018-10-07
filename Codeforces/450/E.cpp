#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef pair<int,int> P;
int n,l;
bool vis[N],he[N];
vector<P>ans;
vector<int>tmp;
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++) if(!he[i]) for(int j=2*i;j<=n;j+=i) he[j]=true;
    for(int i=n/2;i>1; i--)
    {
        if(he[i]) continue;
        tmp.clear();
        for(int j=i;j<=n;j+=i) if(!vis[j]) tmp.push_back(j);
        l=tmp.size();
        if(l&1) swap(tmp[1],tmp[l-1]);
        for(int j=0;j<l-1;j+=2)
        {
            ans.push_back(make_pair(tmp[j],tmp[j+1]));
            vis[tmp[j]]=vis[tmp[j+1]]=1;
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}