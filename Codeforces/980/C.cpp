#include<bits/stdc++.h>
#define N 100010
using namespace std;
int L[N],R[N],cnt,vis[N];
int main(){
	int n,k,a;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(vis[a]){
			printf("%d ",L[vis[a]]);
			continue;
		}
		int l=max(a-k+1,0),h=l;
		bool flag=0;
		while(1){
			if(!vis[l]){
				if(h!=l)R[vis[l-1]]=l-1;
				break;
			}
			if(R[vis[l]]>=a){
//				cout<<endl<<"!"<<endl;
//				cout<<vis[l]<<" "<<cnt<<endl;
				int col=vis[l];
				for(int j=l;j<=a;j++)vis[j]=col;
				printf("%d ",L[vis[l]]);
				flag=1;
				break;
			}
			l++;
		}
		if(flag)continue;
		L[++cnt]=l,R[cnt]=l+k-1;
//		cout<<l<<" "<<l+k-1<<endl;
		for(int j=l;j<=a;j++)vis[j]=cnt;
		printf("%d ",l);
	}
	printf("\n");
	return 0;
}
