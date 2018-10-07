#include<cstdio>
const int m=1e9+7,N=1010;
void gcd(int a,int b,int&x,int &y){
    if(!b){x=1;y=0;}
    else{gcd(b,a%b,y,x);y-=x*(a/b);}
}
int inv(int a){int x,y;gcd(a,m,x,y);return (x%m+m)%m;}
int f[N][N],k,pa,pb,A,B,C;
int main(){
    scanf("%d%d%d",&k,&pa,&pb);
    A=1ll*pa*inv(pa+pb)%m;B=(1-A+m)%m;C=1ll*pa*inv(pb)%m;
    for(int i=k;i;--i)for(int j=k;~j;--j)
        f[i][j]=i+j<k?(1ll*A*f[i+1][j]+1ll*B*f[i][i+j])%m:(i+j+C)%m;
    printf("%d",f[1][0]);
    return 0;
}
