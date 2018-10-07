#include<bits/stdc++.h>
#define N 4005
using namespace std;
int ans[N][N];
int main()
{
    for(int i=0;i<47;++i)
        for(int j=0;j<47;++j)
            for(int k=0;k<47;++k)
                ans[i*47+j][k*47+(j*k+i)%47]=1;
    puts("2000");
    for(int i=0;i<2000;++i,puts(""))
        for(int j=0;j<2000;++j)
            printf("%d",ans[i][j]);
    return 0;
}
