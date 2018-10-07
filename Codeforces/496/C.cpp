#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int  book[110];
int main() {
	int n,m,tot=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j];

	for(int j=1; j<=m; j++) {
		int p=0;
		for(int i=1; i<=n-1; i++)
			if(a[i][j]>a[i+1][j]&&book[i]!=1) {
				tot++;
				p=1;
				break;
			}
		if(p==0)
			for(int i=1; i<=n-1; i++)
				if(a[i][j]<a[i+1][j]) book[i]=1;
	}
	cout<<tot<<endl;
}