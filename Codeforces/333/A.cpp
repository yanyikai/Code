#include<bits/stdc++.h>
using namespace std;
long long n,a=3;
int main()
{
    scanf("%lld",&n);
    while(!(n%a)) a*=3;
    printf("%lld",n/a+1);
    return 0;
}