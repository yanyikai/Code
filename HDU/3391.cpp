#include<cstdio>
#include<cstring>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int num[3][10],tmp[3][10];
inline int rcheck()
{
    int sum=0;
    for(int i=0;i<3;++i)
    for(int j=1;j<10;++j)
    tmp[i][j]=num[i][j];
    for(int i=0;i<3;++i)
    for(int j=1;j<10;++j)
    for(;tmp[i][j];)
    if(tmp[i][j]>2)
    {
        tmp[i][j]-=3;
        ++sum;
    }else
    if(j<8&&tmp[i][j+1]&&tmp[i][j+2])
    {
        --tmp[i][j];
        --tmp[i][j+1];
        --tmp[i][j+2];
        ++sum;
    }else break;
    return sum==4;
}
inline int check()
{
    for(int i=0;i<3;++i)
    for(int j=1;j<10;++j)
    if(num[i][j]>1)
    {
        num[i][j]-=2;
        if(rcheck()){num[i][j]+=2;return 1;}
        num[i][j]+=2;
    }return 0;
}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(num,0,sizeof num);
        int tot=0;
        for(int i=0;i<13;++i)
        {
            int t;char c;
            scanf("%1d%c",&t,&c);
            ++num[c=='s'?0:(c=='b'?1:2)][t];
        }printf("Case %d:",cas);
        for(int i=0;i<3;++i)
        for(int j=1;j<10;++j)
        if(num[i][j]<4)
        {
            ++num[i][j];
            if(check())printf(" %d%c",j,!i?'s':i==1?'b':'c'),++tot;
            --num[i][j];
        }
        puts(tot?"":" None");
    }
    return 0;
}
