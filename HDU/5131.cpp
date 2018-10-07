#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int m[305];
vector<string>a[305];
int main()
{
    for(int n;~scanf("%d",&n)&&n;)
    {
        memset(m,0,sizeof m);
        for(int i=0;i<300;++i)a[i].clear();
        string nam;
        for(int i=0;i<n;++i)
        {
            cin>>nam;int w=read();
            ++m[w];
            a[w].push_back(nam);
        }
        for(int i=1;i<300;++i)
        {
            m[i]+=m[i-1];
            sort(a[i].begin(),a[i].end());
        }
        for(int i=299;i;--i)
        for(vector<string>::iterator it=a[i].begin();it!=a[i].end();++it)
            cout<<*it,printf(" %d\n",i);
        int q=read();
        for(int j=0;j<q;++j)
        {
            cin>>nam;
            for(int i=1;i<300;++i)
            {
                int num=0;
                for(vector<string>::iterator it=a[i].begin();it!=a[i].end();++it)
                {
                    if(*it==nam)
                    {
                        printf("%d",m[299]-m[i]+1);
                        if(num)printf(" %d",num+1);
                        puts("");
                    }
                    ++num;
                }
            }
        }
    }
    return 0;
}
