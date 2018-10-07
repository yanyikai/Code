#include<bits/stdc++.h>
using namespace std;
map<string,string>m0;
map<string,int>m1;
string s;
int main()
{
	m0["purple"]="Power";
	m0["green"]="Time";
	m0["blue"]="Space";
	m0["orange"]="Soul";
	m0["red"]="Reality";
	m0["yellow"]="Mind";
	m1["Power"]=m1["Time"]=m1["Space"]=m1["Soul"]=m1["Reality"]=m1["Mind"]=0;
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		cin>>s;
		m1[m0[s]]=1;
	}
	printf("%d\n",6-n);
	for(auto v:m1)
	if(!v.second)cout<<v.first,puts("");
}
