#include<bits/stdc++.h>
using namespace std;
string s[20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},t[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int n;
int main()
{
	scanf("%d",&n);
	if(n<=19)
	{
		cout<<s[n];
		return 0;
	}
	cout<<t[n/10];
	if(n%10!=0)
	{
		cout<<'-'<<s[n%10];
	}
	return 0;
}