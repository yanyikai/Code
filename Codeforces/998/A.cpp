#include<cstdio>
using namespace std;
int n,a[10],i,k,s;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
		if(a[i]<a[k])k=i;
		s+=a[i];
	}
	n<2||a[k]==s-a[k]?puts("-1"):printf("1 %d",k+1);
	return 0;
}
