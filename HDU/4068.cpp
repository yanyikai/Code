#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int T,n,a[7][7],fa[7],fb[7];
string t,nam[7];map<string,int>m;
inline int check()
{
    int l=1,r=1;
    for(;l<=n&&r<=n;)
        a[fb[r]][fa[l]]?++l:++r;
    return r>l;
}
inline int get()
{
    for(int i=1;i<=n;++i)
        fa[i]=i;
    do
    {
        int flg=1;
        for(int i=1;i<=n;++i)
            fb[i]=i;
        do
        {
            if(!check())flg=0;
        }while(next_permutation(fb+1,fb+n+1));
        if(flg)return 1;
    }while(next_permutation(fa+1,fa+n+1));
    return 0;
}
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        memset(a,0,sizeof a);
        m.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            cin>>nam[i],m[nam[i]]=i;
        for(int i=1;i<=n;++i)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;++j)
            {
                cin>>t;
                a[i][m[t]]=1;
            }
        }printf("Case %d: ",cas);
        if(get())
        {
            puts("Yes");
            for(int i=1;i<n;++i)
                cout<<nam[fa[i]]<<' ';
            cout<<nam[fa[n]];
            puts("");
        }else puts("No");
    }
    return 0;
}
