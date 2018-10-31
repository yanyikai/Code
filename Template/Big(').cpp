#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
class UBig
{
	#define Dlen 4
	#define Base 10000
	#define L long long
	#define Max_Len 50
	private:
		int v[Max_Len];int len;
		inline void strrevv(char *str){char *l=str,*r=str,ch;for(;*r;r++);for(r--;l<r;*r--=ch)ch=*l,*l++=*r;}
	public:
		inline void writeln(){write();puts("");}
		inline void write(){printf("%d",v[len-1]);for(int i=len-2;i>=0;i--)printf("%04d",v[i]);}/*printf("% Dlen d");*/
		//can=use======================================int========long=long========UBig========char========char*========string========//
		UBig():len(1){memset(v,0,sizeof v);}
		UBig(char x):len(0){memset(v,0,sizeof v);v[len++]=x-48;}
		UBig(L x){memset(v,0,sizeof v);if(x)for(len=0;x;x/=Base)v[len++]=x%Base;else len=1;}
		UBig(int x){memset(v,0,sizeof v);if(x)for(len=0;x;x/=Base)v[len++]=x%Base;else len=1;}
		UBig(UBig &x){memset(v,0,sizeof v);len=x.len;for(int i=0;i<len;i++) v[i]=x.v[i];}
		UBig(char* x){memset(v,0,sizeof v);len=0;strrevv(x);int l=strlen(x),i,j;
		for(i=Dlen;i<l;i+=Dlen,len++)for(j=i-1;j>=i-Dlen;j--)v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;
		for(j=l-1;j>=i-Dlen;j--)v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;len++;}
		UBig(std::string x){memset(v,0,sizeof v);len=0;reverse(x.begin(),x.end());int l=x.size(),i,j;
		for(i=Dlen;i<l;i+=Dlen,len++)for(j=i-1;j>=i-Dlen;j--)v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;
		for(j=l-1;j>=i-Dlen;j--) v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;len++;}
		UBig &operator = (const UBig &t){memset(v,0,sizeof v);len=t.len;for(int i=0;i<len;i++) v[i]=t.v[i];return *this;}
		UBig &operator = (const L &t){memset(v,0,sizeof v);L x=t;if(t)for(len=0;x;x/=Base)v[len++]=x%Base;else len=1;return *this;}
		UBig &operator = (const int &t){memset(v,0,sizeof v);int x=t;if(t)for(len=0;x;x/=Base)v[len++]=x%Base;else len=1;return *this;}
		UBig &operator = (const char &t){len=0;memset(v,0,sizeof v);v[len++]=t-48;return *this;}
		UBig &operator = (const char* &t){memset(v,0,sizeof v);len=0;char x[Max_Len*Dlen];strcpy(x,t);strrevv(x);int l=strlen(x),i,j;
		for(i=Dlen;i<l;i+=Dlen,len++)for(j=i-1;j>=i-Dlen;j--)v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;
		for(j=l-1;j>=i-Dlen;j--) v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;len++;return *this;}
		UBig &operator = (const std::string &t){memset(v,0,sizeof v);len=0;std::string x=t;reverse(x.begin(),x.end());int l=x.size(),i,j;
		for(i=Dlen;i<l;i+=Dlen,len++)for(j=i-1;j>=i-Dlen;j--)v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;
		for(j=l-1;j>=i-Dlen;j--) v[len]=(v[len]<<1)+(v[len]<<3)+x[j]-48;len++;return *this;}
		//����==============================֧��========int========long=long========UBig========char========char*========string========//
		UBig operator + (const UBig &t){UBig x(*this);x.len=t.len>len?t.len:len;for(int i=0;i<x.len;i++){x.v[i]+=t.v[i];if(x.v[i]>=Base)x.v[i+1]+=x.v[i]/Base,x.v[i]%=Base;}if(x.v[x.len])x.len++;return x;}
		UBig operator + (const L &t){L x=t,l=0;UBig y(*this);for(;x;x/=Base,l++){y.v[l]+=x%Base;if(y.v[l]>=Base)y.v[l+1]+=y.v[l]/Base,y.v[l]%=Base;}for(;y.v[l]>=Base;)y.v[l+1]+=y.v[l]/Base,y.v[l]%=Base;if(l>y.len)y.len=l;return y;}
		UBig operator + (const int &t){int x=t,l=0;UBig y(*this);for(;x;x/=Base,l++){y.v[l]+=x%Base;if(y.v[l]>=Base)y.v[l+1]+=y.v[l]/Base,y.v[l]%=Base;}for(;y.v[l]>=Base;)y.v[l+1]+=y.v[l]/Base,y.v[l]%=Base;if(l>y.len)y.len=l;return y;}
		UBig operator + (const char &t){UBig x(*this);int l=0;for(x.v[0]+=t-48;x.v[l]>=Base;x.v[++l]++) x.v[l]-=Base;if(l+1>x.len) x.len++;return x;}
		//-
		//*
		///
		//%
		//^
		//--
		//++
		UBig operator ++ (){int l=0;for(v[0]++;v[l]>=Base;v[++l]++) v[l]-=Base;if(l+1>len) len++;}
		UBig operator ++ (int){UBig x(*this);++(*this);return x;}
		//+=
		
		//-=
		//*=
		///=
		//%=
		//==
		//>
		//<
		//>=
		//<=
		//!=
		//>>
//		friend istream& operator >> (isteam& ,UBig& ) const;
		//<<
//		friend ostream& operator << (osteam& ,UBig& ) const;
	#undef Max_Len
	#undef Base
	#undef Len
	#undef L
};
//istream& operator >> (istream& in,UBig& t)
//{
//	
//}
int main()
{
	return 0;
}