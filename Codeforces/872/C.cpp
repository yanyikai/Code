#include<cstdio>
int n,x,a;int main(){for(scanf("%d",&n);n--;x<4&&x?puts("-1"):printf("%d\n",x/4+a)){scanf("%d",&x);if(a=x&1)x-=9;}}
