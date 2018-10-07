#include<bits/stdc++.h>
using namespace std;
long long n,f[10006];
int main(){
    scanf("%lld",&n);
    f[1]=2,f[2]=3;
    if(n==2)return 0*printf("1\n");
    int i=3;
    while(1){
        f[i]=f[i-2]+f[i-1];
        if(f[i]>n)break;
        i++;
    }
    printf("%d\n",i-1);
    return 0;
}
