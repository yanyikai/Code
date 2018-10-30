#include<bits/stdc++.h>
#define N 1000
template<class Tp=int>class Stack
{
	private:
		Tp s[N],*t;
	public:
		Stack():t(s){}
		inline void clear(){t=s;}
		inline void pop(){t==s?perr():--t;}
		inline void Push(Tp x){*(++t)=x;}
		inline Tp top(){return *t;}
		inline int empty(){return t==s;}
		inline void perr(){puts("\n\nEmpty!!!\n");}
};
template<class Tp=int>class Deque
{
	private:
		Tp q[N],*b,*e;
	public:
		Deque():b(q+1),e(q){}
		inline void clear(){b=q+1;e=q;}
		inline Tp front(){return *b;}
		inline Tp back(){return *e;}
		inline void pop_front(){b>e?perr():++b;}
		inline void pop_back(){b>e?perr():--e;}
		inline void push(Tp x){*(++e)=x;}
		inline int empty(){return b>e;}
		inline int size(){return e-b+1;}
		inline void perr(){puts("\n\nEmpty!!!\n");}
};
template<class Tp=int,class cmp=std::greater<Tp> >class Heap
{
	private:
		Tp h[N],*s;
	public:
		Heap():s(h){memset(h,0,sizeof h);}
		inline void clear(){s=h;memset(h,0,sizeof h);}
		inline void size(){return s-h;}
		inline void empty(){return s==h;}
		inline Tp top(){return *(h+1);}
		inline void push(Tp x)
		{
			Tp *i,*t;
			for(;i>h+1&&x<*(t=(i-h)>>1+h);i=t) *i=*t;
			*i=x;
		}
		inline void pop()
		{
			int i=1,p=2,q=3,t;
			for(; p<s&&h[t=q<s&&h[q]<h[p]?q:p]<h[s]; i=t,p=i<<1,q=p|1) h[i]=h[t];
			h[i]=h[s],h[s--]=0;
		}
};
		
int main()
{
	return 0;
}
