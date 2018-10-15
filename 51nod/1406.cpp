#include<cstdio>
#define N 1000001
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int m[N];
int main()
{
    int n=read();
    for(int i=0;i<n;++i)++m[read()];
    for(int p=0;p<20;++p)
        for(int i=N-1;i;--i)
            if(i>>p&1)
                m[i^(1<<p)]+=m[i];
    for(int i=0;i<N;++i)printf("%d\n",m[i]);
    return 0;
}