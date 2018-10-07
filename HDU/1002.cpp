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
char t[1005];
int a[1005],b[1005],la,lb,l;
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        if(cas!=1)puts("");
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        printf("Case %d:\n",cas);
        scanf("%s",t);la=strlen(t);
        for(int i=0;i<la;++i)a[i]=t[la-i-1]-48;
        for(;la!=1&&!a[la-1];)--la;
        for(int i=la-1;~i;--i)printf("%d",a[i]);
        printf(" + ");
        scanf("%s",t);lb=strlen(t);
        for(int i=0;i<lb;++i)b[i]=t[lb-i-1]-48;
        for(;lb!=1&&!b[lb-1];)--lb;
        for(int i=lb-1;~i;--i)printf("%d",b[i]);
        printf(" = ");
        l=la>lb?la:lb;
        for(int i=0;i<l;++i)
        {
            a[i]+=b[i];
            if(a[i]>9)a[i]-=10,++a[i+1];
        }if(a[l])++l;    
        for(int i=l-1;~i;--i)printf("%d",a[i]);
        puts("");
    }
    return 0;
}
