#include<bits/stdc++.h>
#define N 200005
using namespace std;
int a,b;
int main()
{
//	int n;scanf("%d",&n);
//	for(int i=1;i<=n;++i)
//		scanf("%d",a+i);
	char s[500];
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;++i)
		s[i]=='-'?++a:++b; 
	if(b==0||a==0)return puts("YES"),0;
	if(a%b==0)return puts("YES"),0;
	puts("NO");
	return 0;
}
