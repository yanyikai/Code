#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n,pos,l,r;
inline int get()
{
	if(l!=1)
	{
		if(r!=n) return 2+r-l+min(abs(pos-l),abs(pos-r));
		else return abs(pos-l)+1;
	}
	else
	{
		if(r!=n) return abs(pos-r)+1;
		else return 0;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	printf("%d\n",get());
}
