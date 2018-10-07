#include <bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
int T,n,m;
int Pow(int x,int y){
    int ans=1;
    for (;y;y>>=1,x=1LL*x*x%mod)
        if (y&1)
            ans=1LL*ans*x%mod;
    return ans;
}
int Fac[N],Inv[N];
int S[N][405];
int C(int n,int m){
    if (m>n)
        return 0;
    return 1LL*Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int R(int i,int j,int s){
    return (s+C(i,j+1))%mod;
}
int U(int i,int j,int s){
    return (1LL*s*2-C(i,j)+mod)%mod;
}
void Get_S(){
    int s=1;
    S[0][0]=s;
    for (int j=1;j<N;j++){
        s=R(0,j-1,s);
        if (j%250==0)
            S[0][j/250]=s;
    }
    for (int j=0;j<=N/250;j++)
        for (int i=1;i<N;i++)
            S[i][j]=U(i-1,j*250,S[i-1][j]);
}
int main(){
    Inv[0]=Fac[0]=1;
    for (int i=1;i<N;i++){
        Fac[i]=1LL*Fac[i-1]*i%mod;
        Inv[i]=1LL*Inv[i-1]*Pow(i,mod-2)%mod;
    }
    Get_S();
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        int x=m/250,a=x*250;
        int s=S[n][x];
        for (int i=a+1;i<=m;i++)
            s=R(n,i-1,s);
        printf("%d\n",s);
    }
    return 0;
}
