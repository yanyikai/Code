#include<bits/stdc++.h>
int n,r,x[1005],t,i,j;double y[1005];
main(){
	scanf("%d%d",&n,&r);
	for(i=0;i<n;++i){
		scanf("%d",x+i);y[i]=r;
		for(j=0;j<i;++j)
			t=x[i]-x[j],y[i]=std::max(y[i],y[j]+sqrt(4*r*r-t*t));
		printf("%lf ",y[i]);
	}
}
