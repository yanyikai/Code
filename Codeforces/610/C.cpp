#include<bits/stdc++.h>
#define M 1<<9
using namespace std;
char t[M][M];
int l=1,n,e,i,j;
int main()
{
	scanf("%d",&n);t[0][0]='+';
	for(e=1;e<=n;e++)
	{
		for(i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				t[i+l][j]=t[i][j+l]=t[i][j];
				t[i+l][j+l]=t[i][j]=='+'?'*':'+';
			}
		}
		l*=2;
	}
	for(i=0;i<1<<n;i++)
	{
		for(j=0;j<1<<n;j++)
		{
			printf("%c",t[i][j]);
		}
		printf("\n");
	}
	return 0;
}