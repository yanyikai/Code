#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int l,a,b;
inline bool check(char a,char b)
{
	if(a=='A'&&b=='A'||a=='H'&&b=='H'||a=='I'&&b=='I'||a=='M'&&b=='M'||a=='O'&&b=='O'||a=='T'&&b=='T'||a=='U'&&b=='U'||a=='V'&&b=='V'||a=='W'&&b=='W'||a=='X'&&b=='X'||a=='Y'&&b=='Y'||a=='o'&&b=='o'||a=='v'&&b=='v'||a=='w'&&b=='w'||a=='x'&&b=='x'||a=='b'&&b=='d'||a=='d'&&b=='b'||a=='p'&&b=='q'||a=='q'&&b=='p') return true;
	return false;
}
int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	if(l&1) a=b=l/2+1;
	else a=l/2,b=l/2+1;
	while(a!=0&&b!=l+1)
	{
		if(!check(s[a],s[b])) return 0*puts("NIE");
		a--,b++;
	}
	return 0*puts("TAK");
}