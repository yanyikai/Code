#include<cstdio>
using namespace std;
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i)
        printf("%d",i&1);
    return 0;
}
