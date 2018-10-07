#include<stdio.h>
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<n-k;++i)
		printf("%d ",i);
	int l,r;
	for(l=n-k,r=n;r>l;++l,--r)printf("%d %d ",l,r);
	if(l==r)
		printf("%d ",l);
	return 0;
}
