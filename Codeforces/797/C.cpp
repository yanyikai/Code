#include<bits/stdc++.h>
using namespace std;
stack<char> t;
queue<char> s;
map<char,int> num;
char ch='a',c;
bool p;
int main()
{
	num[char('z'+1)]=1;
	while(~scanf("%c",&c)&&c!='\n') s.push(c),num[c]++;
	while(num[ch]==0) ch++;
	while(!s.empty())
	{
		t.push(s.front());
		s.pop();
		num[t.top()]--;
		p=false;
		while(!t.empty())
		{
			for(c=t.top()-1;c>='a';c--) if(num[c]) p=true;
			if(p) break;
			printf("%c",t.top());
			t.pop();
		}
	}
	while(!t.empty()) printf("%c",t.top()),t.pop();
	return 0;
}