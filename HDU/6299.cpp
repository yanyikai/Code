#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
char s[N];
struct P{
    int l,r;
    bool operator<(const P&o)const{
        if(l>=r&&o.l< o.r)return 0;
        if(l< r&&o.l>=o.r)return 1;
        return l<r||o.l<o.r?l<o.l:r>o.r;
    }
}a[N];
int main()
{
    for(int cas=0,T=read();cas<T;++cas)
    {
        int n=read(),ans=0;
        for(int i=0;i<n;++i)
        {
            scanf("%s",s);
            int len=strlen(s),l=0,r=0;
            for(int j=0;j<len;++j)
            {
                if(s[j]=='(')++r;
                else
                {
                    if(r)--r,++ans;
                    else ++l;
                }
            }
            a[i]=P{l,r};
        }
        sort(a,a+n);
        int now=0;
        for(int i=0;i<n;++i)
        {
            if(a[i].l>now)a[i].l=now;
            ans+=a[i].l;
            now+=a[i].r-a[i].l;
        }
        printf("%d\n",ans*2);
    }
    return 0;
}
