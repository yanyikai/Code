#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
	if(n==k||k==0) printf("0 0");
    else printf("1 %d",k>=n/3+1?n-k:2*k);
    return 0;
}