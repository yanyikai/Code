#include<bits/stdc++.h>
using namespace std;
int i,ans,l,k;
char t[5001];
int main()
{
	scanf("%s",t);
	l=strlen(t)-1;
	k=0;
	for(i=0;i<l-2;i++)
	{
		if(t[i]=='b'&&t[i+1]=='e'&&t[i+2]=='a'&&t[i+3]=='r')
		{
			ans+=(i-k+1)*(l-i-2);
			k=i+1;
		}
	}
	printf("%d",ans);
	return 0;
}