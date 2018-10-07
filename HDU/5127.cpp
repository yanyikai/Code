#include<list>
#include<cstdio>
#include<iostream>
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
} 
using namespace std;
list<P >l;
signed main()
{
    for(int n;~scanf("%lld",&n)&&n;)
    {
        l.clear();
        for(int i=0;i<n;++i)
        {
            int k=read(),x=read(),y=read();
            if(k)
            {
                if(~k)l.push_front(P(x,y));
                else
                {
                    P t=P(x,y);
                    for(list<P >::iterator it=l.begin();;++it)
                        if(*it==t)
                        {
                            l.erase(it);
                            break;
                        }
                }
            }else
            {
                int ans=-1e15-7;
                for(list<P >::iterator it=l.begin();it!=l.end();++it)
                ans=max(ans,it->first*x+it->second*y);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
