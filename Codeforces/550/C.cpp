#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;++i)
	{
		if(s[i]%8==0)return printf("YES\n%c",s[i]),0;
		for(int j=i+1;j<n;++j)
		{
			if((s[i]*2+s[j])%8==0)return printf("YES\n%c%c",s[i],s[j]),0;
			for(int k=j+1;k<n;++k)
				if((s[i]*4+s[j]*2+s[k])%8==0)
					return printf("YES\n%c%c%c",s[i],s[j],s[k]),0;
		}
	}
	puts("NO");
	return 0;
}