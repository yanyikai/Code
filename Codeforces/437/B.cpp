#include<cstdio>
#include<vector>
#define N 100005
using namespace std;
int ans;vector<int>a;
int main()
{
    int sum,lim,res=0;
    scanf("%d%d",&sum,&lim);
    for(int i=lim;i;--i)
        if(sum>=(i&-i))
            ++ans,a.push_back(i),sum-=i&-i;
    if(sum)puts("-1");else
    {printf("%d\n",ans);for(int v:a)printf("%d ",v);}
    return 0;
}