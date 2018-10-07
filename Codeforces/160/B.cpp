#include<cstdio>
#include<algorithm>
char s[128],b,l;int n,i;main(){scanf("%d ",&n);gets(s);std::sort(s,s+n);for(std::sort(s+n,s+n*2);i<n;++i){b|=s[i]<=s[i+n];l|=s[i]>=s[i+n];}puts(b&&l?"NO":"YES");}
