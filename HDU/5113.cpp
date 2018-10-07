#include <cstdio>
#include <cstring>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int n,m,k,col[7][7],a[30],flg;
void dfs(int x,int y,int tot){
    if(!tot){flg=1;return ;}
    for(int i=1;i<=k;++i)
        if((tot+1)/2<a[i])return ;
    for(int i=1;i<=k;++i)
    if(a[i]&&col[x-1][y]!=i&&col[x][y-1]!=i)
    {
        col[x][y]=i;
        --a[i];
        if(y+1>m)
            dfs(x+1,1,tot-1);
        else
            dfs(x,y+1,tot-1);
        if(flg)return;
        col[x][y]=0;
        ++a[i];
    }
}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        n=read(),m=read(),k=read();
        memset(col,0,sizeof col);flg=0;
        for(int i=1;i<=k;++i)a[i]=read();
        printf("Case #%d:\n",cas);
        dfs(1,1,n*m);
        if(flg)
        {
            puts("YES");
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    if(j!=1)putchar(' ');
                    printf("%d",col[i][j]);
                }
                puts("");
            }
        }
        else
            puts("NO");
    }
    return 0;
}
