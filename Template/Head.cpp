#pragma GCC optimize(3,"inline,Ofast")
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
// inline int read(){
//     int x=0,f=0;char ch=getchar();
//     for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
//     for(;ch>47&&ch<58;ch=getchar())
//     x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
// }
using namespace std;
signed main()
{
    return 0;
}