#include<cstdio>
#define N 1000005
#define max(a,b) (a>b?a:b)
using namespace std;
int a[N],ans,n,m,k,l,q1[N],q2[N],*b1,*b2,*e1,*e2;
int main()
{
    for(;~scanf("%d %d %d",&n,&m,&k);)
    {
        ans=l=0;
		e1=q1;e2=q2;b1=q1+1;b2=q2+1;
        for(int i=1;i<=n;++i)
        {
        	scanf("%d",a+i);
            for(;!(b1>e1||*(a+i)<*(a+*e1));--e1);
            for(;!(b2>e2||*(a+i)>*(a+*e2));--e2);
            for(*(++e1)=*(++e2)=i;!(b1>e1||b2>e2)&&*(a+*b1)-*(a+*b2)>k;)
                *b1>*b2?l=*(b2++):l=*(b1++);
            if(!(b1>e1||b2>e2||*(a+*b1)-*(a+*b2)<m))
                ans=max(ans,i-l);
        }
        printf("%d\n",ans);
    }
    return 0;
}
