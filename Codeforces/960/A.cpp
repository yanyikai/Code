#include<cstdio>
#include<cstring>
using namespace std;
char s[10000];
int num0,num1,num2,i;
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    if(s[i]!='a'||i==n)return puts("NO"),0;
    for(;s[i]=='a'&&i<n;++i)++num0;
    if(s[i]!='b'||i==n)return puts("NO"),0;
    for(;s[i]=='b'&&i<n;++i)++num1;
    if(s[i]!='c'||i==n)return puts("NO"),0;
    for(;s[i]=='c'&&i<n;++i)++num2;
    if(i!=n)return puts("NO"),0;
    if(num2==num0||num2==num1)return puts("YES"),0;
    return puts("NO"),0;
}
