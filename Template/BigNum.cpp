#pragma GCC optimize(3,"inline,Ofast")
#include<cstdio>
#include<cstring>
#include<assert.h>
using namespace std;
struct UBig{
    #define Len 50
    #define Dlen 4
    #define Base 10000
    #define IL inline
    #define OP operator
    #define C const
    #define R return
    #define L long long
    #define M(_) memset(_,0,sizeof _)
    #define P(u,v,l) memcpy(u,v,(l)*4)
    int v[Len],len;
    IL void rev(char*l){
        for(char*r=l,ch;*r;++r)
            for(--r;l<r;*r--=ch)
                ch=*l,*l++=*r;
    }
    //build:
    UBig():len(0){M(v);}
    UBig(C UBig&o){
        M(v);P(v,o.v,len=o.len);
    }
    UBig(int o):len(0){
        for(M(v);o;o/=Base)
            v[len++]=o%Base;
    }
    UBig(L o):len(0){
        for(M(v);o;o/=Base)
            v[len++]=o%Base;
    }
    //IO:
    IL void write(){
        if(!len)R void(putchar(48));
        printf("%d",v[len-1]);
        for(int i=len-2;~i;--i)
            printf("%04d\n",v[i]);
    }
    IL void writeln(){write();putchar(10);}
    //=
    IL UBig&OP=(C UBig&o){
        if(o.len<len)M(v);
        P(v,o.v,len=o.len);
        R *this;
    }
    IL UBig&OP=(int o){
        for(M(v),len=0;o;o/=Base)
            v[len++]=o%Base;
        R *this;
    }
    IL UBig&OP=(L o){
        for(M(v),len=0;o;o/=Base)
            v[len++]=o%Base;
        R *this;
    }
    //==
    IL bool OP==(C UBig&o)C{
        if(len^o.len)R 0;
        for(int i=0;i<len;++i)
            if(v[i]^o.v[i])
                R 0;
        R 1;
    }
    IL bool OP==(C int&o)C{
        R *this==UBig(o);
    }
    IL bool OP==(C L&o)C{
        R *this==UBig(o);
    }
    //!=
    IL bool OP!=(C UBig&o)C{
        if(len^o.len)R 1;
        for(int i=0;i<len;++i)
            if(v[i]^o.v[i])
                R 1;
        R 0;
    }
    IL bool OP!=(C int&o)C{
        R *this!=UBig(o);
    }
    IL bool OP!=(C L&o)C{
        R *this!=UBig(o);
    }
    //<
    IL bool OP<(C UBig&o)C{
        if(len^o.len)R len<o.len;
        for(int i=len-1;~i;--i)
            if(v[i]^o.v[i])R v[i]<o.v[i];
        R 0;
    }
    IL bool OP<(C int&o)C{
        R *this<UBig(o);
    }
    IL bool OP<(C L&o)C{
        R *this<UBig(o);
    }
    //>
    IL bool OP>(C UBig&o)C{
        if(len^o.len)R len>o.len;
        for(int i=len-1;~i;--i)
            if(v[i]^o.v[i])R v[i]>o.v[i];
        R 0;
    }
    IL bool OP>(C int&o)C{
        R *this>UBig(o);
    }
    IL bool OP>(C L&o)C{
        R *this>UBig(o);
    }
    //<=
    IL bool OP<=(C UBig&o)C{
        if(len^o.len)R len<o.len;
        for(int i=len-1;~i;--i)
            if(v[i]^o.v[i])R v[i]<o.v[i];
        R 1;
    }
    IL bool OP<=(C int&o)C{
        R *this<=UBig(o);
    }
    IL bool OP<=(C L&o)C{
        R *this<=UBig(o);
    }
    //>=
    IL bool OP>=(C UBig&o)C{
        if(len^o.len)R len>o.len;
        for(int i=len-1;~i;--i)
            if(v[i]^o.v[i])R v[i]>o.v[i];
        R 1;
    }
    IL bool OP>=(C int&o)C{
        R *this>=UBig(o);
    }
    IL bool OP>=(C L&o)C{
        R *this>=UBig(o);
    }
    //+
    IL UBig OP+(C UBig&o)C{
        UBig T(*this);
        T.len<o.len?T.len=o.len:0;
        for(int i=0;i<T.len;++i){
            T.v[i]+=o.v[i];
            if(T.v[i]>=Base)
                ++T.v[i+1],T.v[i]-=Base;
        }if(T.v[T.len])++T.len;R T;
    }
    IL UBig OP+(int o)C{
        UBig T(*this);int l=0;
        for(;o;o/=Base,++l){
            T.v[l]+=o/Base;
            if(T.v[l]>=Base)
                ++T.v[l+1],T.v[l]-=Base;
        }if(l>T.len)T.len=l;R T;
    }
    IL UBig OP+(L o)C{
        UBig T(*this);int l=0;
        for(;o;o/=Base,++l)
        {
            T.v[l]+=o/Base;
            if(T.v[l]>=Base)
                ++T.v[l+1],T.v[l]-=Base;
        }if(l>T.len)T.len=l;R T;
    }
    //+=
    IL UBig&OP+=(C UBig&o){
        len<o.len?len=o.len:0;
        for(int i=0;i<len;++i){
            v[i]+=o.v[i];
            if(v[i]>=Base)
                ++v[i+1],v[i]-=Base;
        }if(v[len])++len;R *this;
    }
    IL UBig&OP+=(int o){
        int l=0;
        for(;o;o/=Base,++l){
            v[l]+=o/Base;
            if(v[l]>=Base)
                ++v[l+1],v[l]-=Base;
        }if(l>len)len=l;R *this;
    }
    IL UBig&OP+=(L o){
        int l=0;
        for(;o;o/=Base,++l){
            v[l]+=o/Base;
            if(v[l]>=Base)
                ++v[l+1],v[l]-=Base;
        }if(l>len)len=l;R *this;
    }
    //-
    IL UBig OP-(C UBig&o)C{
        assert(*this>=o);//*this - o < 0;
        UBig T(*this);int l=0;
        for(;l<o.len;++l){
            T.v[l]-=o.v[l];if(T.v[l]<0)
            --T.v[l+1],T.v[l]+=Base;
        }
        for(;T.v[l]<0;++l)
            --T.v[l+1],T.v[l]+=Base;
        for(;T.len&&!T.v[T.len-1];--T.len);
        R T;
    }
    IL UBig OP-(int o)C{
        assert(*this>=o);//*this - o < 0;
        UBig T(*this);int l=0;
        for(;o;o/=Base,++l){
            T.v[l]-=o%Base;if(T.v[l]<0)
            --T.v[l+1],T.v[l]+=Base;
        }
        for(;T.v[l]<0;++l)
            --T.v[l+1],T.v[l]+=Base;
        for(;T.len&&!T.v[T.len-1];--T.len);
        R T;
    }
    IL UBig OP-(L o)C{
        assert(*this>=o);//*this - o < 0;
        UBig T(*this);int l=0;
        for(;o;o/=Base,++l){
            T.v[l]-=o%Base;if(T.v[l]<0)
            --T.v[l+1],T.v[l]+=Base;
        }
        for(;T.v[l]<0;++l)
            --T.v[l+1],T.v[l]+=Base;
        for(;T.len&&!T.v[T.len-1];--T.len);
        R T;
    }
    //-=
    IL UBig&OP-=(C UBig&o){
        assert(*this>=o);//*this - o < 0;
        int l=0;
        for(;l<o.len;++l){
            v[l]-=o.v[l];if(v[l]<0)
            --v[l+1],v[l]+=Base;
        }
        for(;v[l]<0;++l)
            --v[l+1],v[l]+=Base;
        for(;len&&!v[len-1];--len);
        R *this;
    }
    IL UBig&OP-=(int o){
        assert(*this>=o);//*this - o < 0;
        int l=0;
        for(;o;o/=Base,++l){
            v[l]-=o%Base;if(v[l]<0)
            --v[l+1],v[l]+=Base;
        }
        for(;v[l]<0;++l)
            --v[l+1],v[l]+=Base;
        for(;len&&!v[len-1];--len);
        R *this;
    }
    IL UBig&OP-=(L o){
        assert(*this>=o);//*this - o < 0;
        int l=0;
        for(;o;o/=Base,++l){
            v[l]-=o%Base;if(v[l]<0)
            --v[l+1],v[l]+=Base;
        }
        for(;v[l]<0;++l)
            --v[l+1],v[l]+=Base;
        for(;len&&!v[len-1];--len);
        R *this;
    }
    //++
    IL UBig&OP++(){
        ++*v;
        for(int l=0;v[l]>=Base;++l)
            v[l]-=Base,++v[l+1];
        if(v[len])++len;R *this;
    }
    IL UBig OP++(int){
        UBig T(*this);++*this;R T;
    }
    //--
    IL UBig&OP--(){
        assert(len);//*this - 1 < 0;
        for(--v[len-1];v[len-1]<0;--len)
            --v[len-2],v[len-1]=Base-1;
        if(!(len+*v))len=0;R *this;
    }
    IL UBig OP--(int){
        assert(len);//*this - 1 < 0;
        UBig T(*this);--*this;R T;
    }
    #undef L
    #undef M
    #undef R
    #undef OP
    #undef IL
    #undef Dlen
    #undef Base
};
int main(){
    return 0;
}