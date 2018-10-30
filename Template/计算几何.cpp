#include<cmath>
#include<cstdio>
namespace XOY{
	#define eps 1e-6
	#define C const
	#define R return
	#define IL inline
	#define db double
	#define OP operator
	C db pi=acos(-1.0);
	IL db sqr(db x){return x*x;}
	IL int sgn(int x){return x<-eps?-1:x>eps;}
	struct Vec{
		db x,y;Vec():x(0),y(0){}
		Vec(db _x,db _y):x(_x),y(_y){}
		IL void In(){scanf("%lf%lf",&x,&y);}
		IL void Out(){printf("%lf %lf\n",x,y);}
		IL Vec OP+(C Vec&o)C{R Vec(x+o.x,y+o.y);}
		IL Vec OP-(C Vec&o)C{R Vec(x-o.x,y-o.x);}
		IL Vec OP*(C db&o)C{R Vec(x*o,y*o);}
		IL Vec OP/(C db&o)C{R Vec(x/o,y/o);}
		IL Vec OP+=(C Vec&o){x+=o.x;y+=o.y;R *this;}
		IL Vec OP-=(C Vec&o){x-=o.x;y-=o.y;R *this;}
		IL Vec OP*=(C db&o){x*=o;y*=o;R *this;}
		IL Vec OP/=(C db&o){x/=o;y/=o;R *this;}
		IL int OP<(C Vec&o)C{R sgn(x-o.x)<0||(!sgn(x-o.x)&&sgn(y-o.y)<0);}
		IL int OP>(C Vec&o)C{R sgn(o.x-x)<0||(!sgn(x-o.x)&&sgn(o.y-y)<0);}
		IL int OP==(C Vec&o)C{R !(sgn(x-o.x)||sgn(y-o.y));}
		IL int OP<=(C Vec&o)C{R !(*this>o);}
		IL int OP>=(C Vec&o)C{R !(*this<o);}
		IL int OP!=(C Vec&o)C{R !(*this==o);}
		IL db OP&(C Vec&o)C{R x*o.x+y*o.y;}
		IL db OP|(C Vec&o)C{R x*o.y-y*o.x;}
	//	IL db OP^(C Vec&o)C{R 0;}
		IL db OP!()C{R x*x+y*y;}
	};
	IL Vec OP*(C db&k,C Vec&o){R Vec(o.x*k,o.y*k);}
	IL db Dis(C Vec&a,C Vec&b){R sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
	IL db Len(C Vec&o){return sqrt(!o);}
	IL db Ang(C Vec&a,C Vec&b){R acos(a&b)/Len(a)/Len(b);}
	IL db Ang(C Vec&o){R atan2(o.y,o.x);}
	IL db Area2(C Vec&a,C Vec&b,C Vec&c){R (b-a)|(c-a);}
	IL Vec Uni(C Vec&o){R o/Len(o);}
	IL Vec Nom(C Vec&o){R Vec(-o.y,o.x)/Len(o);}
	IL Vec Rot(C Vec&o,db rad){
		return Vec(o.x*cos(rad)-o.y*sin(rad),o.x*sin(rad)+o.y*cos(rad));
	}
	#undef C
	#undef R
	#undef IL
	#undef OP
	#undef db
	#undef eps
}using namespace XOY;
int main()
{
	return 0;
}
