#include<cstdio>
using namespace std;
int main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        int n,res=0;scanf("%d",&n);
        for(int i=0,x;i<n;++i)
            scanf("%d",&x),
            res^=x;
        for(int i=1,u,v;i<n;++i)
            scanf("%d%d",&u,&v);
        if(!res)puts("D");
        else puts("Q");
    }
    return 0;
}
