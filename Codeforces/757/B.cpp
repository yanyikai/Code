#include<iostream>
#include<cstring>
using namespace std;
int s[100005],b[100005];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(b,0,sizeof(b));
        int maxn=0,ans=1;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            b[s[i]]++;
            maxn=max(maxn,s[i]);
        }
        for(int i=2;i<=maxn;i++)
        {
            int sum=0;
            for(int j=i;j<=maxn;j+=i)
              sum+=b[j];
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}