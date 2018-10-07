#include<cstdio>
int n,a,b,i,j,k;
main(){
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i<=n;++i)
	if(!(i%a||(n-i)%b)){
		for(j=1;j<=i;j+=a)
		for(k=1;k<=a;++k)
		printf("%d ",j+k%a);
		for(j=i+1;j<=n;j+=b)
		for(k=1;k<=b;++k)
		printf("%d ",j+k%b);
		return 0;
	}puts("-1");
}
