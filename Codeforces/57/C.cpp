#include<cstdio>
#define int long long
using namespace std;
const int p=1e9+7;
inline int Pow(int x,int y){
    int re=1;
    for(;y;y>>=1,x=x*x%p)if(y&1)re=re*x%p;
    return re;
}
signed main()
{
    int n;scanf("%lld",&n);
    int res=1,ans=1;
    for(int i=1;i<=n;++i)
        res=res*i%p,ans=ans*i%p*(i+n)%p;
    res=Pow(res,p-2);
    printf("%lld\n",(ans*res%p*res%p-n+p)%p);
    return 0;
}
/*
1 1
2 4
3 17
4 66
5 247
6 918
*/