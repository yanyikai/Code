#include<bits/stdc++.h>
using namespace std; 
char a[1000005];
int pos,beg,end,i,e,l;
bool p1=false,p2=false;
int main()
{
	scanf("%s",a);l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]=='.'&&!p2) pos=i,p2=true;
		else if(a[i]!='0'&&!p1) beg=i,p1=true;
		if(p1&&p2) break;
	}
	for(i=l-1;i>=0;i--)
	{
		if(a[i]!='0'&&a[i]!='.')
		{
			end=i;
			break;
		}
	}
	if(!p2) pos=l;
	e=pos-beg;if(e>=0) e--;
	if(beg==end) printf("%c",a[beg]);
	else
	{
		printf("%c.",a[beg]);
		for(i=beg+1;i<=end;i++) if(a[i]!='.') printf("%c",a[i]);
	}
	if(e) printf("E%d",e);
	return 0;
}