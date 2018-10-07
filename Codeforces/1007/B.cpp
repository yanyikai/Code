#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int g(int x)
{
	int n=sqrt(x),res=0;
	for(int i=1;i<=n;++i)
		if(!(x%i))
			res+=i*i==x?1:2;
	return res;
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=0;i<T;++i)
	{
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		int a=g(A),b=g(B),c=g(C),ab=g(__gcd(A,B)),bc=g(__gcd(B,C)),ca=g(__gcd(C,A)),abc=g(__gcd(__gcd(A,B),C));
		printf("%d\n",a*b*c-ab*bc*ca+abc*(ab*bc+bc*ca+ca*ab)-a*bc*(bc-1)/2-b*ca*(ca-1)/2-c*ab*(ab-1)/2-abc*(abc+1)*(ab+bc+ca)/2+abc*(abc+1)*(abc+2)/6);
	}
	return 0;
}
