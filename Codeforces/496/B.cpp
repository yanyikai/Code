#include<bits/stdc++.h>
using namespace std;
int n,i,j,e;
char t[1000];
string s,p;
string min(string x,string y)
{
	return x<y?x:y;
}
int main()
{
	scanf("%d\n%s",&n,t);
	for(i=1;i<=n;i++)
	{
		s+='9';
	}
	for(e=0;e<=9;e++)
	{
		for(i=0;i<n;i++)
		{
			p="";
			for(j=0;j<n;j++)
			{
				p+=t[(i+j)%n];
			}
			s=min(s,p);
		}
		for(i=0;i<n;i++)
		{
			t[i]++;
			if(t[i]>'9') t[i]='0';
		}
	}
	cout<<s;
	return 0;
}