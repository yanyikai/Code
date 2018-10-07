#include<bits/stdc++.h>
using namespace std;
int ans[5][104];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	if(k%2==0) {
		printf("YES\n");
		for(int i=1; i<=4; i++) {
			for(int j=1; j<=n; j++) {
				if(2<=i&&i<=3&&2<=j&&j<=n-1&&j<=k/2+1)putchar('#');
				else putchar('.');
			}
			putchar('\n');
		}
		return 0;
	}
	else{
		printf("YES\n");
		ans[2][n/2+1]=1;
		k--;
		for(int i=2;i<=n/2;i++)if(k)ans[2][i]=ans[2][n-i+1]=1,k-=2;
		for(int i=2;i<=n/2;i++)if(k)ans[3][i]=ans[3][n-i+1]=1,k-=2;
		for(int i=1; i<=4; i++) {
			for(int j=1; j<=n; j++) {
				if(ans[i][j])putchar('#');
				else putchar('.');
			}
			putchar('\n');
		}
		return 0;
	}
	return 0;
}
