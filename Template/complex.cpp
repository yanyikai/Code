#pragma GCC optimize(3,"inline,Ofast")
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
int main(){
	return 0;
}