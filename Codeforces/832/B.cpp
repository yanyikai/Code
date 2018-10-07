#include<bits/stdc++.h>
using namespace std;
int n,lens,lent;
char s[100010],t[100010];
bool flag[130]={0};
bool check(char *s,int lens,char *t,int lent)
{
	int cur=0;
	for(int i=0;i<lent;i++,cur++)
	{
		if(s[cur]!='?'&&s[cur]!='*'&&s[cur]!=t[i])
		{
			return 0;
		}
		if(s[cur]=='?'&&!flag[t[i]]) return 0;
		if(s[cur]=='*')
		{
			for(int j=0;j<=lent-lens;j++)
			{
				if(flag[t[i+j]]) return 0;
			}
			i+=max(-1,lent-lens);
		}
	}
	if(cur<lens-1||(cur==lens-1&&s[cur]!='*')) return 0;
	else return 1;
}
int main()
{
	scanf("%s",s);
	lens=strlen(s);
	for(int i=0;i<lens;i++)
	{
		flag[s[i]]=1;
	}
	scanf("%s%d",s,&n);
	lens=strlen(s);
	while(n--)
	{
		scanf("%s",t);
		lent=strlen(t);
		check(s,lens,t,lent)?printf("YES\n"):printf("NO\n");
	}
	return 0;
}