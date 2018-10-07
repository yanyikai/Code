#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int l,r,p;
	scanf("%d%d%d",&l,&r,&p);
	int t1=min(l,r),t2=max(l,r);
	if(l==r||t1*100/t2>=p)return puts("Ambidextrous"),0;
	l<r?puts("Right-handed"):puts("Left-handed");
	return 0;
}
