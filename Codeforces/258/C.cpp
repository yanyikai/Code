#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int sum[N],n,mx,a[N],ans=0,s[N],top=0,res;

void pp(int n)
{
	for(int i=1;i<=sqrt(n+0.5);i++)
	{
		if(n%i==0)
		{
			s[++top]=i;
			if(i*i!=n) s[++top]=n/i;
		}
	}
}

int pow_mod(int a,int k,int mod)
{
	int ans=1;
	for(;k;k>>=1,a=(a*a)%mod) if(k&1) ans=(ans*a)%mod;
	return ans;
}

void solve(int m)
{
	sort(s+1,s+top+1),res=1;
	for(int i=1;i<top;i++) res=(res*pow_mod(i,sum[s[i+1]-1]-sum[s[i]-1],mod))%mod;
	ans=(ans+(res*(pow_mod(top,sum[N-100]-sum[s[top]-1],mod)-pow_mod(top-1,sum[N-100]-sum[s[top]-1],mod)))%mod)%mod;
}

main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]),sum[a[i]]++;
	for(int i=1;i<=N-10;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=mx;i++)
	{
		top=0,pp(i),solve(i);
	}
	printf("%lld\n",(ans+mod)%mod);
}