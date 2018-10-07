#include<cstdio>
#include<algorithm>
#define N 100005
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N];
signed main()
{
    int n=read(),s=read();
    if(s>n*(n-1)/2)return puts("nO 5oLuTi0N"),0;
    for(int i=1;i<=n;++i)a[i]=i;
    int p=1;
    for(;p*(p-1)/2<s;++p);
    for(int i=1;i<p;++i)a[i]=i+1;
    a[p]=1;
    int del=p*(p-1)/2-s;
    if(del==1)
    {
        p&1?(a[1]=3,a[2]=1):
            (a[1]=1,a[2]=3);
        a[p]=2;
    }
    else if(del>1)swap(a[del],a[del-1]);
    for(int i=1;i<=n;++i)printf("%lld ",a[i]);
    return 0;
}
