#include<bits/stdc++.h>
using namespace std;
char t[15];
int i,ans;
int main()
{
	scanf("%s",t);
	ans+=pow(2,strlen(t))-2;
	for(i=0;i<strlen(t);i++)
	{
		if(t[i]=='7') ans+=pow(2,strlen(t)-i-1);
	}
	printf("%d",ans+1);
	return 0;
}