#include<bits/stdc++.h>
using namespace std;
int m[2];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%1d",&x);
		++m[x];
	}
	if(m[1])putchar('1');
	for(int i=0;i<m[0];++i)
		putchar('0');
	return 0;
}
