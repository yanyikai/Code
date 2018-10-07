#include<bits/stdc++.h>
#define P pair<int,int>
#define N 100005
using namespace std;
int main()
{
	int n,h,a,b,k;
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	for(int i=0;i<k;++i)
	{
		int ta,fa,tb,fb;
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		if(ta==tb)printf("%d\n",abs(fa-fb));
		else
		{
			int x=fa<a?a-fa:(fa>b?fa-b:0);
			if(fa<a)fa=a;if(fa>b)fa=b;
			int y=fb<a?a-fb:(fb>b?fb-b:0);
			if(fb<a)fb=a;if(fb>b)fb=b;
			printf("%d\n",abs(ta-tb)+x+y+abs(fa-fb));
		}
	}
	return 0;
}
