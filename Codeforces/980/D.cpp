#include<cstdio>
#include<cmath>
int n,a[5005],ans[5005],fir[5005],k;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i){
		if(!a[i]){fir[i]=i;continue;}
		for(int j=i-1;j>=1;--j)
		{
			if(!a[j])continue;
			long long p=1ll*a[i]*a[j];
			if(p<0)continue;
    		long long s=sqrt(p);
			if(s*s==p)
			{
				fir[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		k=0;
		for(int j=i;j<=n;++j)
		{
			if(fir[j]<i)++k;
			++ans[k>1?k:1];
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}