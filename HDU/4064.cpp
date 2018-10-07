#include<cstdio>
#include<cstring>
#define p 1000000007
#define F(i,n) for(int i=0;i<n;++i)
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int map[12][12][4],now,mul,n,m,pow[13]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441};
long long dp[2][531441];
void get(int i,int j,int l,int r,int con)
{
//    printf("%d %d %d %d %d %d %d\n",i,j,l,r,con,mul,now);
    if(j==m)return void(dp[now][r]=(dp[now][r]+(i?dp[now^1][l]*mul:mul))%p);
    if(map[i][j][0]==map[i][j][1]&&map[i][j][1]==map[i][j][2]&&map[i][j][2]==map[i][j][3])
    {
        int thi=map[i][j][0];mul*=4;
        if(con==-1||con==thi)get(i,j+1,l*3+thi,r*3+thi,thi);
        mul/=4;return;
    }F(k,4)
        if(con==-1||con==map[i][j][k])
            get(i,j+1,l*3+map[i][j][(k+1)%4],r*3+map[i][j][(k+3)%4],map[i][j][(k+2)%4]);
}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(dp[now],0,sizeof dp[now]);
        n=read(),m=read();
        F(i,n)F(j,m)
        {
            char s[6];scanf("%s",s);F(k,4)
            map[i][j][k]=s[k]=='C'?0:(s[k]=='R'?1:2);
        }
        F(i,n)
        {
            now^=1;memset(dp[now],0,sizeof dp[now]);
            mul=1;get(i,0,0,0,-1);
        }long long ans=0;
        F(i,pow[m])ans=(dp[now][i]+ans)%p;
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
