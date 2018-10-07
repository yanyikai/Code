#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int i,k;
int main()
{
	getline(cin,s1);
	getline(cin,s2);
	int l=s1.size();
	for(i=0;i<l;i++)
	{
		if(s1[i]!=s2[i]) k++;
	}
	if(k%2)
	{
		printf("impossible");
		return 0;
	}
	k/=2;
	for(i=0;i<l;i++)
	{
		if(s1[i]!=s2[i])
		{
			if(k>0)
			{
				k--;
				printf("%c",s1[i]);
			}
			else printf("%c",s2[i]);
		}
		else printf("%c",s1[i]);
	}
	return 0;
}