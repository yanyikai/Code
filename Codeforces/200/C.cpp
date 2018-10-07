#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct Team { int point,got,lost,p;string name; }team[5],tmp[5];
map<string,int> m;
bool cmp(Team x,Team y)
{
	if(x.point!=y.point)
		return x.point>y.point;
	if((x.got-x.lost)!=(y.got-y.lost))
		return (x.got-x.lost)>(y.got-y.lost);
	if(x.got!=y.got)
		return x.got>y.got;
	return x.name<y.name;
}
int cnt=1,i,x,y,ansx=INF,ansy=INF,get,lost,cha,now=1,other;
string a,b;
int main()
{
	m["BERLAND"]=1;team[1].name="BERLAND";
	for(i=1;i<6;i++)
	{
		cin>>a>>b;
		scanf("%d:%d\n",&x,&y);
		if(!m[a]) m[a]=++cnt,team[cnt].name=a;
		if(!m[b]) m[b]=++cnt,team[cnt].name=b;
		if(x>y)
			team[m[a]].point+=3;
		else
		if(x<y)
			team[m[b]].point+=3;
		else
			team[m[a]].point++,team[m[b]].point++;
		team[m[a]].p++;
		team[m[b]].p++;
		team[m[a]].got+=x;
		team[m[b]].lost+=x;
		team[m[b]].got+=y;
		team[m[a]].lost+=y;
	}
	for(i=2;i<=4;i++)
		if(team[i].p==2) other=i;
	for(cha=50;cha>0;cha--)
	{
		for(lost=50;lost>=0;lost--)
		{
			get=cha+lost;
			tmp[1]=team[1];
			tmp[2]=team[2];
			tmp[3]=team[3];
			tmp[4]=team[4];
			tmp[now].got+=get;
			tmp[other].lost+=get;
			tmp[other].got+=lost;
			tmp[now].lost+=lost;
			if(get>lost)
				tmp[now].point+=3;
			else
			if(get<lost)
				tmp[other].point+=3;
			else
				tmp[now].point++,
				tmp[now].point++;
			sort(tmp+1,tmp+5,cmp);
			if(tmp[1].name=="BERLAND"||tmp[2].name=="BERLAND")
			{
				ansx=get;
				ansy=lost;
			}
		}
	}
	if(ansx==INF||ansy==INF) return 0*puts("IMPOSSIBLE");
	else printf("%d:%d",ansx,ansy);
	return 0;
}