#include<cstdio>
#define N 10000001 
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x; 
}
using namespace std;
int a[N<<2]={0,1};
int main()
{
    int tot=1,x=1;
    for(int i=1;i<N;++i)
    {
        if(!a[i])a[i]=a[i-1]==1?2:1;
        for(int j=0;j<a[i];++j)a[tot++]=x;
        x=x==1?2:1;
    }
    for(int T=read(),cas=1;cas<=T;++cas)
        printf("%d\n",a[read()]);
    return 0;
}
