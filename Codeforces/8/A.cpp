#include<bits/stdc++.h>
using namespace std;
string t,s1,s2,ans[4]={"fantasy","forward","backward","both"};
int p;
int main()
{
    cin>>t>>s1>>s2;
    if(t.find(s1)!=-1&&t.find(s2,t.find(s1)+s1.size())!=-1) p++;
    reverse(t.begin(),t.end());
    if(t.find(s1)!=-1&&t.find(s2,t.find(s1)+s1.size())!=-1) p+=2;
    cout<<ans[p];
}