#pragma GCC optimize(3,"inline,Ofast")
#include<cmath>
#include<algorithm>
#define N 100
namespace Fast_mul
{
	#define Re register
	const double pi=acos(-1);
	template<typename Tp=double>struct Complex{
		Tp x,y;//x+yi;
		Complex():x(0),y(0){}
		Complex(Tp _x,Tp _y):x(_x),y(_y){}
		Complex operator+(const Complex&o)const{
			return Complex(x+o.x,y+o.y);
		}
		Complex operator+=(const Complex&o){
			return Complex(x+=o.x,y+=o.y);
		}
		Complex operator-(const Complex&o)const{
			return Complex(x-o.x,y-o.y);
		}
		Complex operator-=(const Complex&o){
			return Complex(x-=o.x,y-=o.y);
		}
		Complex operator*(const Complex&o)const{
			return Complex(x*o.x-y*o.y,x*o.y+y*o.x);
		}
		Complex operator*=(const Complex&o){
			return *this=Complex(x*o.x-y*o.y,x*o.y+y*o.x);
		}
	};
	int n,m,l,R[N];Complex<double>a[N],b[N];/*[0,n)*/
	inline void init(){
		for(m=n<<1,n=1,l=0;n<=m;n<<=1)++l;
		for(Re int i=0;i<n-1;++i)
			R[i]=(R[i>>1]>>1)|((i&1)<<(l-1));
	}
	inline void FFT(Complex<double>*a,int f)/*~f?DFT:IDFT*/
	{
		for(Re int i=0;i<n-1;++i)
			if(i<R[i])std::swap(a[i],a[R[i]]);
		for(Re int i=1;i<n;i<<=1)
		{
			Complex<double>wn(cos(pi/i),f*sin(pi/i));
			for(Re int j=0;j<n;j+=i<<1)
			{
				Complex<double>w(1,0);
				for(Re int k=0;k<i;++k)
				{
					Complex<double>t=w*a[i+j+k];
					a[i+j+k]=a[j+k]-t;
					a[j+k]+=t;
					w*=wn;
				}
			}
		}
		if(!~f)for(int i=0;i<n-1;++i)a[i].x/=n;
	}
	inline void doit()
	{
		init();FFT(a,1);FFT(b,1);
		for(Re int i=0;i<n;++i)
			a[i]*=b[i];FFT(a,-1);
	}
}
namespace FFT_NTT
{
	#define LL long long
	const LL p=998244353;
	int n,m,l,R[N];LL a[N],b[N],P[N],I[N];
	inline LL Pow(LL x,LL y){
		LL res=1;
		for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;
		return res;
	}
	inline void init(){
		m=n<<1;for(n=1,l=0;n<=m;n<<=1)++l;
		for(Re int i=0;i<n-1;++i)
			R[i]=(R[i>>1]>>1)|((i&1)<<(l-1));
		for(Re int i=1;i<=n;i<<=1)
			P[i]=Pow(3,(p-1)/i);
		for(Re int i=1;i<=n;i<<=1)
			I[i]=Pow(332748118,(p-1)/i);
	}
	inline void NTT(LL*a,int f)
	{
		for(Re int i=0;i<n-1;++i)
			if(i<R[i])std::swap(a[i],a[R[i]]);
		for(Re int i=1;i<n;i<<=1)
		for(Re int j=0;j<n;j+=i<<1)
		{
			LL w=1,wn=~f?P[i<<1]:I[i<<1];
			for(Re int k=0;k<i;++k)
			{
				LL t=a[i+j+k]*w%p;
				a[i+j+k]=(a[j+k]-t+p)%p;
				a[j+k]=(a[j+k]+t)%p;
				w=w*wn%p;
			}
		}
		if(!~f)
		{
			LL inv=Pow(n,p-2);
			for(int i=0;i<n;++i)
				a[i]=a[i]*inv%p;
		}
	}
	inline void doit()
	{
		init();NTT(a,1);NTT(b,1);
		for(Re int i=0;i<n;++i)
			a[i]=a[i]*b[i]%p;
		NTT(a,-1);
	}
}
