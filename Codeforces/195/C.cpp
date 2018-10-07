#include<bits/stdc++.h>
using namespace std;
int got,n;
char s[101],a[101],b[101],c[101],ans[101]={"Unhandled Exception"};
bool check()
{
	int thr=0;
	while(~scanf("%*[^a-z]%[a-z]",s),s[1]!='a')
	{
		if(s[1]=='r') thr|=check();
		if(s[1]=='h') scanf("%*[^a-zA-Z]%[a-zA-Z]",a),thr=1;
	}
	scanf("%*[^a-zA-Z]%[a-zA-z]%*[^\"]\"%[^\"]",b,c);
	if(thr&&!got&&!strcmp(a,b)) got=1,strcpy(ans,c);
	return thr;
}
int main()
{
	scanf("%d",&n);
	while(~scanf("%*[^a-z]%[a-z]",s),s[1]=='r') check();
	printf("%s",ans);
}