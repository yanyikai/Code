#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int num[25],P=2520,f[25][2520][50];map<int,int>m;
int L[]={1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,21,24,28,30,35,36,40,42,45,56,60,63,70,72,84,90,105,120,126,140,168,180,210,252,280,315,360,420,504,630,840,1260,2520};
int Lcm(int a,int b){int c=__gcd(a,b);return a*b/c;}
int dfs(int p,int fir,int mod,int lcm)
{
    if(!p)return !(mod%L[lcm]);
    if(!fir&&~f[p][mod][lcm])return f[p][mod][lcm];
    int res=0,up=fir?num[p]:9;
    for(int i=0;i<=up;++i)
        res+=dfs(p-1,fir&&i==num[p],(mod*10+i)%P,i?m[Lcm(L[lcm],i)]:lcm);
    return fir?res:f[p][mod][lcm]=res;
}
int get(int x)
{
    int tot=0;
    for(;x;x/=10)num[++tot]=x%10;
    return dfs(tot,1,0,0);
}
signed main()
{
    for(int i=0;i<48;++i)m[L[i]]=i;
    memset(f,-1,sizeof f);
    int T;scanf("%lld",&T);
    for(int l,r;T--;)
        scanf("%lld%lld",&l,&r),
        printf("%lld\n",get(r)-get(l-1));
    return 0;
}