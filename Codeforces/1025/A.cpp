#include<cstdio>
using namespace std;
char s[100005];
int a[28];
int main()
{
	int n,f=0;
	scanf("%d%s",&n,s);
	if(n==1)return puts("YES"),0;
	for(int i=0;i<n;++i)
		a[s[i]-'a']++;
	for(int i=0;i<26;++i)
		f+=a[i]==1;
	puts(f!=n?"YES":"NO");
	return 0;
}
