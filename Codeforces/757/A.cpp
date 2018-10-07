#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
string s;
int ans,i;
int main()
{
	getline(cin,s);
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='B'||s[i]=='u'||s[i]=='l'||s[i]=='b'||s[i]=='a'||s[i]=='s'||s[i]=='r') m[s[i]]++;
	}
	while(m['B']>=1&&m['u']>=2&&m['l']>=1&&m['b']>=1&&m['a']>=2&&m['s']>=1&&m['r']>=1)
	{
		ans++;
		m['B']-=1;m['u']-=2;m['l']-=1;m['b']-=1;m['a']-=2;m['s']-=1;m['r']-=1;
	}
	printf("%d",ans);
	return 0;
}