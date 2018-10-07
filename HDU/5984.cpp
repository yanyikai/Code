#include<cmath>
#include<cstdio>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        double l,d;
        scanf("%lf%lf",&l,&d);
        printf("%.6lf\n",l>d?log(l/d)+1:0);
    }
    return 0;
}
