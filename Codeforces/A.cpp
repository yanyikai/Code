#include<cstdio>
#include<algorithm>
#define N 100005
#define P pair<int,int>
// #define int long long
using namespace std;
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
char s[105];
int main()
{
    int n=read(),sum=0;
    scanf("%s",s);
    for(int i=0;i<n;++i)if(s[i]=='8')++sum;
    printf("%d\n",min(sum,n/11));
    return 0;
}
