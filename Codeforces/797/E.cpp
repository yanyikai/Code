#include<bits/stdc++.h>
using namespace std;
int ans,a[100005][351],p,k,n,m,i,j;
int main()
{
	for(scanf("%d",&n),i=1;i<=n;i++) scanf("%d",&a[i][0]);
	for(j=1;j<=350;j++)
	{
		for(i=n;i>=1;i--)
		{
			a[i][0]+i+j>n?a[i][j]=1:a[i][j]=a[a[i][0]+i+j][j]+1;
		}
	}
	for(scanf("%d",&m),i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&k);
		if(k<=350) printf("%d\n",a[p][k]);
		else
		{
			ans=0;
		    while(a[p][0]+p+k<=n)
		    {
			    p=a[p][0]+p+k;
			    ans++;
		    }
		    printf("%d\n",ans+1);
		}
	}
	return 0;
}