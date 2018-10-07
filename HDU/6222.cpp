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
int t[55][35],l[55],num[35],n;char s[35];
inline int put(int x)
{
    for(int i=l[x]-1;~i;--i)
        printf("%d",t[x][i]);
    puts("");return 0;
}
inline int cmp(int x)
{
    if(l[x]!=n)return l[x]>n;
    for(int i=n-1;~i;--i)
        if(t[x][i]!=num[i])return t[x][i]>num[i];
    return 1;
}
inline int get()
{
    scanf("%s",s);n=strlen(s);
    for(int i=0;i<n;++i)
        num[i]=s[n-i-1]-48;
    for(int i=0;i<55;++i)if(cmp(i))
    return i;
}
int main()
{
    t[0][0]=4;l[0]=1;
    t[1][0]=4;t[1][1]=1;l[1]=2;
    for(int i=2;l[i-1]<32;++i)
    {
        l[i]=l[i-1];
        for(int j=0;j<l[i];++j)
        {
            t[i][j]+=t[i-1][j]*4;
            t[i][j+1]+=t[i][j]/10;
            t[i][j]%=10;
        }if(t[i][l[i]])++l[i];
        for(int j=0;j<l[i-2];++j)
        {
            t[i][j]-=t[i-2][j];
            if(t[i][j]<0)
                t[i][j]+=10,--t[i][j+1];
        }if(!t[i][l[i]-1])--l[i];
    }
    for(int T=read(),cas=1;cas<=T;++cas)put(get());
    return 0;
}
