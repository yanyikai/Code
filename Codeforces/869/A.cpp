#include<bits/stdc++.h>
#define f(i,r) for (i=0;i<=r;i++)
#define g(i,r) for (i=1;i<=r;i++)
typedef long long L;
L C[205][205],k,t,l,p[22][250],e[25],s,i,j;
L qiu(int l,int d=0)
{
	int i,j,k;
	f(i,l) f(j,16) p[j][i]=0;p[0][l]=1;
	g(i,16) f(j,l) if(p[i-1][j]!=0) f(k,e[i])
	{
		if(j<k) break;
		p[i][j-k]+=p[i-1][j]*C[j][k];
	}
	return d?p[16][0]/16*15:p[16][0];
}
main()
{
	f(i,199) f(j,i) C[i][j]=j?C[i-1][j]+C[i-1][j-1]:1;
	scanf("%I64d%I64d",&k,&t);
	g(i,16) e[i]=t;
	g(l,99)
	{
		s=qiu(l,1);
		if(s>=k) break;
		k-=s;
	}
	g(i,l) g(j,16) if(i!=1||j!=1)
	{
		e[j]--;
		s=qiu(l-i);
		if(s>=k)
		{
			printf("%c",j<11?char(j+47):char(j+86));
			break;
		}k-=s,e[j]++;
	}
}
