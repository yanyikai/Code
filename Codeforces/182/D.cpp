#include<bits/stdc++.h>
using namespace std;
string s,t;
long long ans;
bool check(string s,int l)
{
	for(int i=0;i<s.size();i++) if(s[i]!=t[i%l]) return false;
	return true;
}
int main()
{
	cin>>s>>t;
	for(int i=1;i<=min(s.size(),t.size());i++) if(s.size()%i==0&&t.size()%i==0&&check(s,i)&&check(t,i)) ans++;
	printf("%d\n",ans);
	return 0;
}