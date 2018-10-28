    #include<cstdio>
    #include<algorithm>
    using namespace std;
    int main(){
        int T;scanf("%d",&T);
        for(int k,a,b,c,d;T--;puts("")){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int l=0,r=a+b+1;k=(max(a,b)-1)/(min(a,b)+1)+1;
            for(int mid;l<r;){
                mid=(l+r)>>1;
                if(b-mid/(k+1)<=1ll*(a-mid/(k+1)*k-mid%(k+1))*k)
                    l=mid+1;else r=mid;
            }
            r=l+b-l/(k+1)-(a-l/(k+1)*k-l%(k+1))*k+1;
            for(int i=c;i<=min(d,l);++i)
                putchar(i%(k+1)?'A':'B');
            for(int i=max(c,l+1);i<=d;++i)
                putchar((i-r)%(k+1)?'B':'A');
        }
        return 0;
    }