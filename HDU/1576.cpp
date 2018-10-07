#include<cstdio>
int T,a,b;int Pow(int x,int y){int res=1;for(;y;y>>=1,x=x*x%9973) if(y&1) res=res*x%9973;return res;}
int main(){
for(scanf("%d",&T);T--;){
scanf("%d%d",&a,&b);b%=9973;
printf("%d\n",a*Pow(b,9971)%9973);}}
