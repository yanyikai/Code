#include <bits/stdc++.h>
#define L 179000
using namespace std;int n,M,i,v,s,t,x[L],y[L];
int main(){cin>>n>>M>>x[0];y[0]=x[0];for(v=0,i=1;i<n;i++)cin>>x[i],y[i]+=y[i-1]+v*(x[i]-x[i-1]),v=!v;
for(s=t=y[i-1]+v*(M-x[n-1]),i=0; i<n; i++)s=max(s,2*y[i]+M-x[i]-t-1);cout<<s;}
