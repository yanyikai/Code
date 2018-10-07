#include<bits/stdc++.h>
// #define P pair<int,int>
// #define int long long
typedef long long LL;
typedef double db;
using namespace std;
inline int read()
{
    int x=0,f=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
int main()
{
    int n=read();
    for(int i=0;i<n;++i)
    {
        int a,b;char c;double d;
        scanf("%d %d UTC%c%lf",&a,&b,&c,&d);
        int tim=a*60+b;if(c=='-')d=-d+24;
        int tmp=(d*10-80)*6;
        // printf("%d\n",tmp);
        if(tmp<0)tmp+=1440;
        tim=(tim+tmp)%1440;
        printf("%.02d:%.02d\n",tim/60,tim%60);
    }
    return 0;
}
