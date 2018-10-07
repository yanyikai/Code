#pragma GCC optimize(3)
#include<cstdio>
#define N 500100
    #define R register
    static int son[N][2],fat[N],key[N],val[N],siz[N],rt,tot,pos,sum;
    inline void PU(int x){siz[x]=son[x][0][siz]+son[x][1][siz]+val[x];}
    inline void Rot(int x)
    {
        R int y=fat[x],z=fat[y],k=son[y][0]==x;
        son[z][son[z][1]==y]=x;fat[x]=z;
        son[y][!k]=son[x][k];son[x][k][fat]=y;
        son[x][k]=y;fat[y]=x;PU(y);
    }
    inline void Spl(int x,int goal)
    {
        for(;fat[x]!=goal;Rot(x))
        {
            R int y=fat[x],z=fat[y];
            if(z!=goal)(son[y][0]==x)^(son[z][0]==y)?Rot(x):Rot(y);
        }PU(x);if(!goal)rt=x;
    }
    inline void Fin(int x)
    {for(pos=rt;son[pos][x>key[pos]]&&x!=key[pos];pos=son[pos][x>key[pos]]);Spl(pos,0);}
    inline void Nex(int x,int k)
    {
        Fin(x);if(!(key[pos]>x&&k||key[pos]<x&&!k))
        for(pos=son[pos][k];son[pos][!k];pos=son[pos][!k]);
    }
    inline void Ins(int x)
    {
        R int fa=0;
        for(pos=rt;pos&&key[pos]!=x;pos=son[pos][x>key[pos]])fa=pos;
        if(pos)++val[pos];else
        {
            pos=++tot;
            son[fa][x>key[fa]]=pos;
            son[pos][0]=son[pos][1]=0;
            fat[pos]=fa;key[pos]=x;val[pos]=siz[pos]=1;
        }Spl(pos,0);
    }
    inline void Del(int x)
    {
        Nex(x,1);R int p=pos;
        Fin(-1e9);Spl(p,rt);
        sum+=p[son][0][siz];
        son[p][0]=0;
        PU(p);PU(rt);
    }
    inline int Kth(int k)
    {
        if(k<2||k+1>siz[rt])return 0;
        for(pos=rt;;)
        {
            R int y=son[pos][0];
            if(k>siz[y]+val[pos])
            {
                k-=siz[y]+val[pos];
                pos=son[pos][1];
            }else
            if(siz[y]<k)return 1;
            else pos=y;
        }
    }
inline int read(){int x=0,f=0;register char ch=getchar();for(;ch<48||ch>57;ch=getchar())f|=ch=='-';for(;ch>47&&ch<58;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return f?-x:x;}
int main()
{
    char s[5];int now=0;
    Ins(-1e9);Ins(+1e9);
    int n=read(),minn=read();
    for(int i=0;i<n;++i)
    {
        scanf("%s",s);int k=read();
        switch(s[0])
        {
            case 'I':if(k>=minn)Ins(k-now);break;
            case 'A':now+=k;break;
            case 'S':now-=k;Del(minn-now-1);break;
            case 'F':printf("%d\n",Kth(siz[rt]-k)?key[pos]+now:-1);break;
        }
    }printf("%d\n",sum);
}
