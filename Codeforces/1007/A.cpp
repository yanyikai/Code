#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],ans;
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i),b[i]=a[i];
    sort(a+1,a+n+1,greater<int>());sort(b+1,b+n+1,greater<int>());
    for(int i=1,l=1,r=n;i<=n;++i)
    {
        if(a[l]>b[i])
            ++ans,++l;
        else
            --r;
    }
    printf("%d\n",ans);
    return 0;
}
