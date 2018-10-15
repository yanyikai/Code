#include<cstdio>
#define N 1000005
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
    for(int i=0;i<n;++i)
        ++m[read()];
    for(int i=N-1;i;--i)
    {
        int cnt=0;
        for(int j=i;j<N;j+=i)cnt+=m[j];
        if(cnt>1)return printf("%d\n",i),0;
    }
    return 0;
}