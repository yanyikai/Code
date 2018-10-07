#include<cstdio>
#include<cstring>
#define p 1000000007
using namespace std;
char s[1000005];
long long dp[1000005][9];
int main()
{
	scanf("%s",s);int n=strlen(s);s[n]='?';
	switch(*s)
	{
		case '0':
			dp[0][0]=1;
			break;
		case '1':
			dp[0][2]=1;
			break;
		case '2':
			return puts("0"),0;
			break;
		case '*':
			dp[0][6]=1;
			break;
		case '?':
			dp[0][0]=1;
			dp[0][2]=1;
			dp[0][6]=1;
			break;
	}
	for(int i=1;i<=n;++i)
	{
		switch(s[i])
		{
			case '0':
				dp[i][0]=(dp[i-1][0]+dp[i-1][1])%p;
				dp[i][1]=dp[i-1][4];
				break;
			case '1':
				dp[i][2]=(dp[i-1][0]+dp[i-1][1])%p;
				dp[i][3]=dp[i-1][4];
				dp[i][4]=(dp[i-1][6]+dp[i-1][7]+dp[i-1][8])%p;
				break;
			case '2':
				dp[i][5]=(dp[i-1][6]+dp[i-1][7]+dp[i-1][8])%p;
				break;
			case '*':
				dp[i][6]=(dp[i-1][2]+dp[i-1][3])%p;
				dp[i][7]=dp[i-1][5];
				dp[i][8]=(dp[i-1][6]+dp[i-1][7]+dp[i-1][8])%p;
				break;
			case '?':
				dp[i][0]=(dp[i-1][0]+dp[i-1][1])%p;
				dp[i][1]=dp[i-1][4];
				dp[i][2]=(dp[i-1][0]+dp[i-1][1])%p;
				dp[i][3]=dp[i-1][4];
				dp[i][4]=(dp[i-1][6]+dp[i-1][7]+dp[i-1][8])%p;
				dp[i][5]=(dp[i-1][6]+dp[i-1][7]+dp[i-1][8])%p;
				dp[i][6]=(dp[i-1][2]+dp[i-1][3])%p;
				dp[i][7]=dp[i-1][5];
				dp[i][8]=(dp[i-1][6]+dp[i-1][7]+dp[i-1][8])%p;
				break;
		}
	}
//	for(int i=0;i<9;++i)
//	printf("%lld ",dp[5][i]);puts("");
//	for(int i=0;i<9;++i)
//	printf("%lld ",dp[6][i]);puts("");
	printf("%lld\n",(dp[n][0]+dp[n][1]+dp[n][4])%p);
	return 0;
}
/*
00
10
01
11
*1
*2
1*
2*
**
*/
