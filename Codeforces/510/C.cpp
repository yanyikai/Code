#include<bits/stdc++.h>
char a[105][105],s[30];
int d[30][30],n,k;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%s",a[i]);
	for(int i=1,j;i<n;++i)
	{
		for(j=0;a[i][j]&&a[i][j]==a[i-1][j];++j);
        if(a[i][j]&&a[i-1][j])
			d[a[i][j]-'a'][a[i-1][j]-'a']=1;
        if(!a[i][j]&&a[i-1][j])
			return puts("Impossible"),0;
	}
	for(int i=0;i<26;++i)s[i]=i+'a';
	for(int i=0;i<26;++i)
		for(int j=0;j<26;++j)
			for(int k=j+1;k<26;++k)if(d[s[j]-'a'][s[k]-'a'])
        		std::swap(s[j],s[k]);
	for(int j=0;j<26;++j)
		for(int k=j+1;k<26;k++)
			if(d[s[j]-'a'][s[k]-'a'])
				return puts("Impossible"),0;
	puts(s);return 0;
}
