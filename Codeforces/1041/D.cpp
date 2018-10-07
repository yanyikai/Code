#include<bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
int x[N],y[N];
signed main(){
	int n,h,r=1,sy,ans=0;scanf("%lld%lld",&n,&h);
	for(int i=1;i<=n;++i)scanf("%lld%lld",x+i,y+i);
    sy=h;
	for(int l=1;l<=n;++l){
		if(l!=1)sy+=x[l]-y[l-1];
		for(;r<n&&sy+y[r]>x[r+1];++r)sy-=x[r+1]-y[r];
		ans=max(ans,y[r]-x[l]+sy);
	}
	;
	return printf("%lld\n",ans),0;
}
