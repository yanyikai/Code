#include<cstdio>
#include<cstring>
using namespace std;
int m[26];char s[200005];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	long long ans=1ll*n*(n+1)/2;
	for(int i=0;i<n;++i)
		++m[s[i]-'a'];
	for(int i=0;i<n;++i)
		ans-=(m[s[i]-'a']--);
	printf("%lld\n",ans+1);
	return 0;
}