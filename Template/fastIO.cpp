#include<cmath>
#include<iostream>
namespace fastIO{int IOE=0;
    #define BUF_SIZE 100005
    #define OUT_SIZE 100005
    #define L long long
    #define SC static
	#define IL inline
    #define D double
    #define C char
	IL int blank(C ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    //fread
	IL C nc(){SC C buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;if(p1==pend){p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);if(pend==p1){IOE=1;return -1;}}return *p1++;}
    IL void read(int &x){int s=0;C ch=nc();for(x=0;blank(ch);ch=nc());if(IOE)return;if(ch=='-')s=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=(x<<1)+(x<<3)+ch-'0';if(s)x=-x;}
    IL void read(L &x){int s=0;C ch=nc();for(x=0;blank(ch);ch=nc());if(IOE)return;if(ch=='-')s=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=(x<<1)+(x<<3)+ch-'0';if(s)x=-x;}
    IL void read(D &x){int s=0;C ch=nc();for(x=0;blank(ch);ch=nc());if(IOE)return;if(ch=='-')s=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(ch=='.'){D t=1;for(ch=nc();ch>='0'&&ch<='9';ch=nc())t/=10.0,x+=t*(ch-'0');}if(s)x=-x;}
    IL void read(C *s){C ch=nc();for(;blank(ch);ch=nc());if(IOE)return;for(;!blank(ch)&&!IOE;ch=nc())*s++=ch;*s=0;}IL void read(C &c){for(c=nc();blank(c);c=nc());if(IOE){c=-1;return;}}
    //getchar
    IL void read1(int &x){C ch;int s=0;for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')s=1;for(x=0;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+ch-'0',ch=getchar());if(s)x=-x;}
    IL void read1(L &x){C ch;int s=0;for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')s=1;for(x=0;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+ch-'0',ch=getchar());if(s)x=-x;}
    IL void read1(D &x){C ch;int s=0;for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')s=1;for(x=0;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());if(ch=='.'){D t=1;for(ch=getchar();ch>='0'&&ch<='9';t/=10.0,x+=t*(ch-'0'))ch=getchar();}if(s)x=-x;}
    IL void read1(C *s){C ch=getchar();for(;blank(ch);ch=getchar());for(;!blank(ch);ch=getchar())*s++=ch;*s=0;}IL void read1(C &c){for(c=getchar();blank(c);c=getchar());}
    //scanf
    IL void read2(int &x){scanf("%d",&x);}IL void read2(D &x){scanf("%lf",&x);}IL void read2(C *s){scanf("%s",s);}IL void read2(C &c){scanf(" %c",&c);}IL void readln2(C *s){gets(s);}
    IL void read2(L &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can not recognize the system!");
        #endif
        #endif
    }
    //fwrite
    struct OS{C *buf,*p1,*pend;
    OS(){buf=new C[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}void out(C ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
    void print(int x){SC C s[15],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;for(;x;x/=10)*s1++=x%10+'0';for(;s1--!=s;out(*s1));}void println(int x){print(x);out('\n');}
    void print(L x){SC C s[25],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;for(;x;x/=10)*s1++=x%10+'0';for(;s1--!=s;out(*s1));}void println(L x){print(x);out('\n');}
    void print(D x,int y){SC L mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
    if(x<-1e-12)out('-'),x=-x;x*=mul[y];L x1=(L)floor(x);if(x-floor(x)>=0.5)++x1;L x2=x1/mul[y],x3=x1-x2*mul[y];print(x2);if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'))i++;print(x3);}}
    void println(D x,int y){print(x,y);out('\n');}void print(C *s){for(;*s;out(*s++));}void println(C *s){for(;*s;out(*s++));out('\n');}void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
    ~OS(){flush();}}os;
    IL void print(int x){os.print(x);}IL void println(int x){os.println(x);}IL void print(C x){os.out(x);}IL void println(C x){os.out(x);os.out('\n');}
	IL void print(L x){os.print(x);}IL void println(L x){os.println(x);}IL void print(D x,int y){os.print(x,y);}IL void println(D x,int y){os.println(x,y);}
	IL void print(C *s){os.print(s);}IL void println(C *s){os.println(s);}IL void println(){os.out('\n');}IL void flush(){os.flush();}
    //puts
    C Out[OUT_SIZE],*o=Out;IL void print1(int x){SC C buf[15];C *p1=buf;if(!x)*p1++='0';if(x<0)*o++='-',x=-x;for(;x;x/=10)*p1++=x%10+'0';for(;p1--!=buf;)*o++=*p1;}IL void println1(int x){print1(x);*o++='\n';}
	IL void print1(L x){SC C buf[25];C *p1=buf;if(!x)*p1++='0';if(x<0)*o++='-',x=-x;for(;x;x/=10)*p1++=x%10+'0';for(;p1--!=buf;)*o++=*p1;}IL void println1(L x){print1(x);*o++='\n';}IL void print1(C c){*o++=c;}
	IL void println1(C c){*o++=c;*o++='\n';}IL void print1(C *s){while (*s)*o++=*s++;}IL void println1(C *s){print1(s);*o++='\n';}IL void println1(){*o++='\n';}IL void flush1(){if(o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    //printf
    IL void print2(int x){printf("%d",x);}IL void println2(int x){printf("%d\n",x);}IL void print2(C x){printf("%c",x);}IL void println2(C x){printf("%c\n",x);}IL void println2(){printf("\n");}
    IL void print2(L x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can not recognize the system!");
        #endif
        #endif
    }IL void println2(L x){print2(x);printf("\n");}
    #undef L
    #undef D
    #undef C
    #undef IL
    #undef SC
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
