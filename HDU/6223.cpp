#include<cstdio>
#include<cstring>
#define N 150005
#define int long long
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int num[N],nex[N],ans[20],res[20],pos;
signed main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(ans,0,sizeof ans);pos=-1;
        int n=read();for(int i=0;i<n;++i)
        scanf("%1lld",num+i),nex[i]=(i*i+1)%n;
        int m=n>20?20:n;
        for(int i=0;i<n;++i)
        {
            int x=i;res[0]=num[x];
            for(int j=1;j<m;++j)
            res[j]=num[x=nex[x]];
            for(int j=0;j<m;++j)
            if(res[j]>ans[j])
            {
                for(int k=j;k<m;++k)
                ans[k]=res[k];pos=i;
                break;
            }else if(res[j]<ans[j])break;
        }
        printf("Case #%lld: %lld",cas,num[pos]);
        for(int i=1;i<n;++i)
            printf("%lld",num[pos=nex[pos]]);
        puts("");
    }
    return 0;
}
