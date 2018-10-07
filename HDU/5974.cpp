#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
inline int gcd(int a,int b){
	for(;b;b^=a^=b^=a)a%=b;
	return a;
}
signed main()
{
	for(int a,b;~scanf("%lld%lld",&a,&b);)
	{
		int c=gcd(a,b),t=a*a-4*b*c;
		if(t<0){puts("No Solution");continue;}
		int tmp=sqrt(t);
		if(tmp*tmp!=t||(tmp+a)%2)
			{puts("No Solution");continue;}
		int x=(a+tmp)/2,y=a-x;
		if(x>y)x^=y^=x^=y;
		printf("%lld %lld\n",x,y);
	}
	return 0;
}
