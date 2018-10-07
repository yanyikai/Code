#include<bits/stdc++.h>
using namespace std;
int n,ans;
char c;
int main()
{
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) scanf("%c",&c),c=='1'?ans++:ans--;
	return 0*printf("%d",abs(ans));
}
