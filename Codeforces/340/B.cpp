#include<bits/stdc++.h>
#define ii pair<double,double>
using namespace std;
int n,i,j,k;
double ans_h,ans_d,ans;
ii t[305];
inline double L(ii x,ii y)
{
	return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
inline double S(ii x,ii y,ii z)
{
	double a=L(x,y),b=L(x,z),c=L(y,z),p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
inline bool check(ii x,ii y,ii z)
{
	return (z.first-x.first)*(y.second-x.second)/(y.first-x.first)+x.second<z.second;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lf%lf",&t[i].first,&t[i].second);
	sort(t+1,t+n+1);
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			ans_h=0;ans_d=0;
			for(k=1;k<=n;k++)
			{
				if(k==i||k==j) continue;
				check(t[i],t[j],t[k])?ans_h=max(ans_h,S(t[i],t[j],t[k])):ans_d=max(ans_d,S(t[i],t[j],t[k]));
			}
			if(ans_h&&ans_d) ans=max(ans,ans_h+ans_d);
		}
	}
	printf("%lf",ans);
	return 0;
}