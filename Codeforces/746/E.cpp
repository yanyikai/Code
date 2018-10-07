#include<bits/stdc++.h>
#define N 200005
#define M 
#define INF 0x3f3f3f3f
#define P pair<L,L>
#define L long long
#define MEM(n,i) memset(n,i,sizeof(n))
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D double
//#define int long long
//#define %d %lld
using namespace std;
int n,m,cnt,odd=1,even=2,ans,a[N];
bool p=true;
map<int,int>mp;

void godd(int i)
{
    while(odd<=m&&mp[odd])
	{
		odd+=2;
	} 
    if(odd>m) p=0;
    else
    {
    	mp[a[i]]--;
		mp[odd]=1;
		a[i]=odd;
		odd+=2;
	}
}
void geven(int i)
{
    while(even<=m&&mp[even]) even+=2;
    if(even>m) p=0;
    else
    {
    	mp[a[i]]--;
		mp[even]=1;
		a[i]=even;
		even+=2;
	}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
        if(a[i]%2==1) cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[a[i]]==1) continue;
        ans++;
        if(cnt>n/2)
        {
            if(a[i]%2==1) cnt--;
            geven(i);
        }
        else
        if(cnt==n/2) a[i]%2?godd(i):geven(i);
        else
		{
            if(a[i]%2==0) cnt++;
            godd(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt==n/2) break;
        if(cnt<n/2)
        {
            if(a[i]%2==0)
            {
                cnt++,ans++;
                godd(i);
            }
        }
        else
        {
            if(a[i]%2==1)
            {
                cnt--,ans++;
                geven(i);
            }
        }
    }
    if(cnt!=n/2||!p) return 0*printf("-1\n");
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}