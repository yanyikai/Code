#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x,y;scanf("%lf%lf",&x,&y);
	if(log(x)*y>log(y)*x)puts(">");else
	if(log(x)*y<log(y)*x)puts("<");else
	return puts("="),0;
}
