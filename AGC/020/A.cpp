#include<cstdio>
#define P pair<int,int>
#define int long long
const int N=1e5+5,p=1e9+7;
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
signed main()
{
    read();int a=read(),b=read();
    puts((a^b)&1?"Borys":"Alice");
    return 0;
}