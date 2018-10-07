#include<bits/stdc++.h>
using namespace std;
int x1,x2,x3,y11,y2,y3;
int main()
{
	scanf("%d%d%d%d%d%d",&x1,&y11,&x2,&y2,&x3,&y3);
	printf("3\n");
	printf("%d %d\n",x1-x2+x3,y11-y2+y3);
	printf("%d %d\n",x1+x2-x3,y11+y2-y3);
	printf("%d %d\n",x2+x3-x1,y2+y3-y11);
	return 0;
}