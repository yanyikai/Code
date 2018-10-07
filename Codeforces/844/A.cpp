#include<bits/stdc++.h>
using namespace std;
char t[1000];
int ans,k,i,j;
bool p[27];
int main()
{
	scanf("%s",t);
	scanf("%d",&k);
	int l=strlen(t);
	if(k>l)
	{
		printf("impossible");
		return 0;
	}
	for(i=0;i<l;i++)
	{
		p[t[i]-'a'+1]=true;
	}
	for(i=1;i<=26;i++)
	{
		if(p[i])
		{
			ans++;
		}
	}
	if(ans>=k)
	{
		printf("0");
	}
	else printf("%d",k-ans);
	return 0;
}