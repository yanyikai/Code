#include<cstdio>
using namespace std;
main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        int k;scanf("%d",&k);
        if(k==1)puts("5");else
        if(k==2)puts("7");else
        printf("%d\n",k+5);
    }
    return 0;
}
