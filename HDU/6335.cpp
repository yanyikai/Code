#include <bits/stdc++.h>
using namespace std;
const int N=105;
int T,n,m;
struct Node{
    int a,b;
}p[N];
bool cmp(Node a,Node b){
    return a.b<b.b;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&p[i].a,&p[i].b);
        sort(p+1,p+n+1,cmp);
        int ans=0;
        for (int i=1;i<=n;i++){
            m/=p[i].b+1;
            if (m)
                ans++;
            else
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
