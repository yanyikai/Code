#include<cstdio>
#include<cstring>
#define N 3005
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N],del[N][3],cnt[4],vis[N],p=1e8+7,fac2[N],fac3[N];
/*
1: can't put, 0: can put.
[0]: A
[1]: B
[2]: C
*/
void Ins(int p,int c,int v){
    --cnt[!del[p][0]+!del[p][1]+!del[p][2]];
    del[p][c]+=v;
    ++cnt[!del[p][0]+!del[p][1]+!del[p][2]];
}
signed main()
{
    *fac2=*fac3=1;
    int n=read(),num=0,ans=0;
    for(int i=1;i<=n;++i)
    {
        fac2[i]=fac2[i-1]*2%p;
        fac3[i]=fac3[i-1]*3%p;
        if(!vis[a[i]=read()])
            ++num,vis[a[i]]=1;
    }
    for(int i=1;i<=n;++i)
    {
        memset(del,0,sizeof del);
        cnt[0]=cnt[1]=cnt[2]=0;cnt[3]=num;
        for(int j=1;j<i;++j)Ins(a[j],0,1);
        Ins(a[i],1,1);Ins(a[i],2,1);
        for(int j=i+1;j<=n;++j)Ins(a[j],2,1);
        for(int j=i+1;j<=n;++j)
        {
            Ins(a[j],0,1);
            if(!*cnt)(ans+=fac2[cnt[2]]*fac3[cnt[3]]%p)%=p;
            Ins(a[j],0,-1);
            Ins(a[j],1,1);
            Ins(a[j],2,-1);
        }
        if(!*cnt)(ans+=fac2[cnt[2]]*fac3[cnt[3]]%p)%=p;
    }
    printf("%lld\n",((fac3[num]-fac2[num]-ans)%p+p)%p);
    return 0;
}
