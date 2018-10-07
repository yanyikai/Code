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
int num[4][10],tmp[4][10],ans[35],tot;
inline int rcheck()
{
    int sum=0;
    for(int i=0;i<4;++i)
    for(int j=1;j<10;++j)
    tmp[i][j]=num[i][j];
    for(int i=0;i<3;++i)
    for(int j=1;j<10;++j)
    {
        for(;tmp[i][j];)
        {
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
        }
    }for(int i=1;i<8;++i)
        if(tmp[3][i]==3)
            ++sum;
    return sum==4;
}
inline int check()
{
    int sum=0;
    for(int i=0;i<4;++i)
    for(int j=1;j<10;++j)
    if(num[i][j])sum+=num[i][j]!=2;
    if(!sum)return 1;sum=0;
    if(num[0][1]&&num[0][9]&&num[1][1]&&num[1][9]&&num[2][1]&&num[2][9]&&num[3][1]&&num[3][2]&&num[3][3]&&num[3][4]&&num[3][5]&&num[3][6]&&num[3][7])
    {
        if(num[0][1]==2)++sum;
        if(num[0][9]==2)++sum;
        if(num[1][1]==2)++sum;
        if(num[1][9]==2)++sum;
        if(num[2][1]==2)++sum;
        if(num[2][9]==2)++sum;
        if(num[3][1]==2)++sum;
        if(num[3][2]==2)++sum;
        if(num[3][3]==2)++sum;
        if(num[3][4]==2)++sum;
        if(num[3][5]==2)++sum;
        if(num[3][6]==2)++sum;
        if(num[3][7]==2)++sum;
        if(sum==1)return 1;sum=0;
    }
    for(int i=0;i<4;++i)
    for(int j=1;j<10;++j)
    if(num[i][j]>1)
    {
        num[i][j]-=2;
        if(rcheck()){num[i][j]+=2;return 1;}
        num[i][j]+=2;
    }
    return 0;
}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(num,0,sizeof num);tot=0;
        for(int i=0;i<13;++i)
        {
            int t;char c;
            scanf("%1d%c",&t,&c);
            ++num[c=='m'?0:(c=='s'?1:(c=='p'?2:3))][t];
        }
        for(int j=0;j<3;++j)
        for(int i=1;i<10;++i)
        if(num[j][i]<4)
        {
            ++num[j][i];
            if(check())ans[++tot]=j*100+i;
            --num[j][i];
        }for(int i=1;i<8;++i)
        if(num[3][i]<4)
        {
            ++num[3][i];
            if(check())ans[++tot]=300+i;
            --num[3][i];
        }
        if(!tot)puts("Nooten");
        else
        {
            printf("%d",tot);
            for(int i=1;i<=tot;++i)
            {
                int t=ans[i]/100;
                printf(" %d%c",ans[i]%100,!t?'m':t==1?'s':t==2?'p':'c');
            }puts("");
        }
    }
    return 0;
}
