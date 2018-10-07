#include<cstdio>
#define N 105
#define P pair<int,int>
// #define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[26],cnt;
int main()
{
    int n=read();
    if(n<=26)
    {
        for(int i=0;i<n;++i)
            printf("%c\n",'a'+i);
        return 0;
    }
    for(int i=1;i<n-1;++i)
    {
        ++a[(i-1)%22];
        printf("%c\n",(i-1)%22+'a');
    }
    for(int i=0;i<22;++i)
        if(a[i])cnt+=a[i]*(a[i]-1)/2;
    putchar('z');
    for(int i=0;i<cnt/2;++i)
        putchar('y'+(i&1));
    puts("");
    putchar('x');
    for(int i=0;i<cnt-cnt/2;++i)
        putchar('w'+(i&1));
    return 0;
}
