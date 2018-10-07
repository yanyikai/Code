#include<iostream>
using namespace std;
long long n,a,b,cnt;string s;
main()
{
	cin>>n>>a>>b>>s;
	s="1"+s+"1";
	for(int i=1;i<s.size();++i) if (s[i-1]=='1' && s[i]=='0') cnt++;
	cnt?cout<<min(a,b)*(cnt-1)+b:cout<<0;
}
