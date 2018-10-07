#include<bits/stdc++.h>
using namespace std;
int n,i;string x;multiset<string> a;
main(){
	cin>>n;
	for(;i<n;++i)cin>>x,a.insert(x);
	for(i=0;i<n;++i){
		cin>>x;
		auto p=a.find(x);
		if(p!=a.end())a.erase(p);
	}
	cout<<a.size();
}
