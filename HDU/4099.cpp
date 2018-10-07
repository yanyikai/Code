#include<cstdio>
#include<cstring>
#define N 3800005
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x; 
}
int num[N],nex[10][N],tot;
inline void Ins(char *a,int id)
{
    int pos=0;
    for(int i=0;a[i]&&i<41;++i)
    {
        int t=a[i]-48;
        pos=(nex[t][pos]?nex[t][pos]:nex[t][pos]=++tot);
        if(num[pos]==-1)num[pos]=id;
    }
}
inline int Fin(char *a)
{
    int pos=0;
    for(int i=0;a[i];++i)
    {
        pos=nex[a[i]-48][pos];
        if(!pos)return -1;
    }return num[pos];
}
char a[52],b[52],sum[55];
int main()
{
    memset(num,-1,sizeof num);
    *a=*b='1';a[1]=b[1]=0;Ins(a,0);int c=0;
    for(int i=2;i<100000;++i)
    {
        int la=strlen(a)-1,lb=strlen(b)-1,l=0;
        if(lb>49)
            a[la--]=b[lb--]=0;
        for(int x,y;~la||~lb||c;c=(x+y+c)/10)
        {
            x=~la?a[la--]-48:0;
            y=~lb?b[lb--]-48:0;
            sum[l++]=(x+y+c)%10+48;
        }
        for(int j=0;j<l>>1;++j)
        {
            sum[j]^=sum[l-j-1];
            sum[l-j-1]^=sum[j];
            sum[j]^=sum[l-j-1];
        }sum[l]=0;Ins(sum,i);
        strcpy(a,b);strcpy(b,sum);
    }
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        scanf("%s",a);
        printf("Case #%d: %d\n",cas,Fin(a));
    }
    return 0;
}
