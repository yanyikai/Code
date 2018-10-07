#include<bits/stdc++.h>
using namespace std;
string s;
int u,r,l,d,n;
int main() {
	cin>>s;
	u=r=l=d=0;
	n=s.size();
	if(n%2==1) {
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++) {
		if(s[i]=='U')u++;
		if(s[i]=='R')r++;
		if(s[i]=='L')l++;
		if(s[i]=='D')d++;
	}
	cout<<(abs(u-d)+abs(l-r))/2<<endl;
	return 0;
}