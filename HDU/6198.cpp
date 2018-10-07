#include<cstdio>
#include<map>
using namespace std;
const int p=998244353;
map<int,int>mp;
inline int sqr(int x){
	return 1ll*x*x%p;
}
inline int f(int x)
{
	// printf("%d\n",x);
	if(!x||mp[x])return mp[x];
	if(x&1)
		return mp[x]=(sqr(f(x/2+1))+sqr(f(x/2)))%p;
	return mp[x]=(2*f(x/2-1)%p+f(x/2))%p*1ll*f(x/2)%p;
}
int main()
{
	mp[1]=1;
	for(int n;~scanf("%d",&n);)
		printf("%d\n",(f(2*n+3)-1+p)%p);
	return 0;
}
/*
0 0
1 1
2 1
3 2
4 3
5 5
6 8
7 13
*/
