#include<cstdio>
#include<map>
#define N 100005
using namespace std;
int a[N];long long ans;
map<int,int>m[N],res;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	m[1][a[1]]=1;res[a[1]]=1;
	for(int i=2;i<=n;++i)
	{
		for(auto v:m[i-1])
			m[i][v.first|a[i]]=v.second;
		m[i][a[i]]+=1;
		for(auto v:m[i])
			res[v.first]+=v.second;
	}
	printf("%d\n",(int)res.size());
	return 0;
}