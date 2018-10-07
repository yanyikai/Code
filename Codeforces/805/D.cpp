#include<cstdio>
#include<cstring>
using namespace std;
char s[1000005];
long long ans,num;
int main()
{
	scanf("%s",s+1);
	for(int i=strlen(s+1);i;--i)
	{
		if(s[i]=='a')
		{
			ans=(ans+num)%1000000007;
			num=num*2%1000000007;
		}else ++num;
	}
	printf("%lld",ans);
	return 0;
}
