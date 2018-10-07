#include<bits/stdc++.h>
using namespace std;
queue<int> D,R;
int n,i,d,r;
char c;
int main()
{
	for(scanf("%d\n",&n),i=0;i<n;i++) scanf("%c",&c),c=='D'?D.push(i):R.push(i);
	while(!D.empty()&&!R.empty())
	{
		d=D.front();r=R.front();
		D.pop();R.pop();
		d<r?D.push(n+d):R.push(n+r);
	}
	D.empty()?printf("R"):printf("D");
	return 0;
}