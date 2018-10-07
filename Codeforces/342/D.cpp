#include<cstdio>
#include<vector>
#include<cstring>
#define N 10005
#define p 1000000007
#define int long long
using namespace std;
int f[N][8],m[3][N],n,sx,sy,res;
vector<int>d;char s[3][N];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
main()
{
	scanf("%lld%s%s%s",&n,s[0]+1,s[1]+1,s[2]+1);
	for(int j=1;j<=n;++j)
		for(int i=0;i<3;++i)
		{
			m[i][j]=s[i][j]!='.';
			if(s[i][j]=='O')
				sx=i,sy=j;
		}
	if(sx==0&&!m[1][sy]&&!m[2][sy])d.push_back(0);
	if(sx==2&&!m[1][sy]&&!m[0][sy])d.push_back(1);
	if(sy<n-1&&!m[sx][sy+1]&&!m[sx][sy+2])d.push_back(2);
	if(sy>  2&&!m[sx][sy-1]&&!m[sx][sy-2])d.push_back(3);
	for(int k=1;k<1<<d.size();++k)
	{
		for(int i=0;i<(int)d.size();++i)
		if((k>>i)&1)for(int j=1;j<3;++j)
		m[sx+dx[d[i]]*j][sy+dy[d[i]]*j]=1;

		memset(f,0,sizeof f);f[0][7]=1;
		for(int i=1;i<=n;++i)
		{
			int sta=m[0][i]+m[1][i]*2+m[2][i]*4;
			for(int j=0;j<8;++j)
			{
				if(j&sta)continue;
				f[i][j|sta]=f[i-1][7-j];
				if(j==3||j==6)
					(f[i][j|sta]+=f[i-1][7])%=p;
				if(j==7)
					(f[i][j|sta]+=f[i-1][3]+f[i-1][6])%=p;
			}
		}
		(res+=__builtin_popcount(k)&1?f[n][7]:-f[n][7])%=p;
		// printf("%lld\n",res);
		for(int i=0;i<(int)d.size();++i)
		if((k>>i)&1)for(int j=1;j<3;++j)
		m[sx+dx[d[i]]*j][sy+dy[d[i]]*j]=0;
	}
	printf("%lld\n",(res%p+p)%p);
	return 0;
}