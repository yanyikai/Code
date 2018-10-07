#include<cstdio>
#define L long long
using namespace std;
L a,b,flg,pow[19]={1};
int num[10],cnt;
void dfs(int pos,L sta)
{
//	printf("%d %lld\n",pos,sta);
	if(!pos)
	{
		flg=sta;
		return ;
	}
	for(int i=9;~i;--i)
		if(num[i]&&sta+pow[pos-1]*i<=b)
		{
			--num[i];
			dfs(pos-1,sta+pow[pos-1]*i);
			if(flg) return ;
			++num[i];
		}
}
int main()
{
	for(int i=1;i<19;++i)pow[i]=pow[i-1]*10;
	scanf("%lld%lld",&a,&b);
	for(;a;a/=10)++cnt,++num[a%10];
	dfs(cnt,0);printf("%lld",flg);
	return 0;
}
