#include<cstdio>
using namespace std;
int main()
{
    char s[3];
    int a=(1<<10)-1,b=0,n;
    scanf("%d",&n);
    for(int i=0,x;i<n;++i)
    {
        scanf("%s%d",s,&x);
        if(*s=='&')
            a&=x,b&=x;
        if(*s=='|')
            a|=x,b|=x;
        if(*s=='^')
            a^=x,b^=x;
    }
    puts("3");
    printf("| %d\n",a&b);
    printf("& %d\n",a|b);
    printf("^ %d\n",(a^b)&b);
    return 0;
}