#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m[15];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<15;++i)m[i]=5e8;
	for(int i=0;i<n;++i)
	{
		int c,sta=0;char s[4];
		scanf("%d%s",&c,s);
		int n=strlen(s);
		for(int j=0;j<n;++j)
			sta|=1<<(s[j]-'A');
		m[sta]=min(m[sta],c);
	}
	int ans=5e8;
	for(int i=1;i<1<<3;++i)
		for(int j=0;j<1<<3;++j)
			for(int k=0;k<1<<3;++k)
				if((i|j|k)==7)
					ans=min(ans,m[i]+m[j]+m[k]);
	printf("%d\n",ans<5e8?ans:-1);
	return 0;
}
