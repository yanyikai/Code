#include<cstring>
template<typename Tp=int>struct Marix{
	#define L 10
	#define F(_) for(int _=0;_<L;++_)
	Tp v[L][L];
	Marix(){memset(v,0,sizeof v);}
	Marix(int x){
		memset(v,0,sizeof v);
		if(x)F(i)v[i][i]=1;
	}
	Marix operator+(const Marix&o)const{
		Marix<Tp>T;
		F(i)F(j)T.v[i][j]=v[i][j]+o.v[i][j];
		return T;
	}
	Marix operator+=(const Marix&o){
		F(i)F(j)v[i][j]+=o.v[i][j];
		return *this;
	}
	Marix operator-(const Marix&o)const{
		Marix<Tp>T;
		F(i)F(j)T.v[i][j]=v[i][j]-o.v[i][j];
		return T;
	}
	Marix operator-=(const Marix&o){
		F(i)F(j)v[i][j]-=o.v[i][j];
		return *this;
	}
	Marix operator*(const Marix&o)const{
		Marix<Tp>T;
		F(k)F(i)F(j)T.v[i][j]+=v[i][k]*o.v[k][j];
		return T;
	}
	Marix operator*=(const Marix&o){
		Marix<Tp>T;
		F(k)F(i)F(j)T.v[i][j]+=v[i][k]*o.v[k][j];
		return *this=T;
	}
	void Clear(){memset(v,0,sizeof v);}
	#undef L
	#undef F
};
