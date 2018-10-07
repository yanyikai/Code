#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int len=sqrt(n),flag1=0,flag2=0;
    for(int i=2;i<=len;i++){
        if(n%i==0)flag1=1;
        if((n-2)%i==0)flag2=1;
    }
    if(!flag1)return 0*printf("1\n");
    if(n%2==0)return 0*printf("2\n");
    if(!flag2)return 0*printf("2\n");
    printf("3\n");
    return 0;
}
