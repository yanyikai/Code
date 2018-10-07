#include<bits/stdc++.h>
using namespace std;
int a[3005],b[3005];
int main()
{
	int n,ans=1e9;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	for(int i=2;i<n;++i)
	{
		int mnn=1e9,mxn=1e9;
		for(int j=1;j<i;++j)
			if(a[j]<a[i])
				mnn=min(mnn,b[j]);
		for(int j=i+1;j<=n;++j)
			if(a[j]>a[i])
				mxn=min(mxn,b[j]);
//		printf("%d %d %d\n",mnn,mxn,ans);
		ans=min(ans,mnn+mxn+b[i]);
	}
	printf("%d\n",ans==1e9?-1:ans);
}
