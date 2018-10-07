#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

int a[30];
int b[30];

void init()
{
    for(int i=1;i<=24;i++)
        b[i]=a[i];
}

bool cube()
{
    for(int i=1;i<=4;i++)
        if(b[i]!=b[1]) return false;
    for(int i=5;i<=8;i++)
        if(b[i]!=b[5]) return false;
    for(int i=9;i<=12;i++)
        if(b[i]!=b[9]) return false;
    for(int i=13;i<=16;i++)
        if(b[i]!=b[13]) return false;
    for(int i=17;i<=20;i++)
        if(b[i]!=b[17]) return false;
    for(int i=21;i<=24;i++)
        if(b[i]!=b[21]) return false;
    return true;
}

void swap1(){
    b[2]=a[14];b[4]=a[16];b[6]=a[2];b[8]=a[4];b[10]=a[6];b[12]=a[8];b[14]=a[10];b[16]=a[12];
}
void swap2(){
    b[14]=a[2];b[16]=a[4];b[2]=a[6];b[4]=a[8];b[6]=a[10];b[8]=a[12];b[10]=a[14];b[12]=a[16];
}
void swap3(){
    b[21]=a[1];b[22]=a[2];b[12]=a[21];b[11]=a[22];b[17]=a[12];b[18]=a[11];b[1]=a[17];b[2]=a[18];
}
void swap4(){
    b[17]=a[1];b[18]=a[2];b[12]=a[17];b[11]=a[18];b[21]=a[12];b[22]=a[11];b[1]=a[21];b[2]=a[22];
}
void swap5(){
    b[13]=a[19];b[14]=a[17];b[22]=a[13];b[24]=a[14];b[8]=a[22];b[7]=a[24];b[19]=a[8];b[17]=a[7];
}
void swap6(){
    b[19]=a[13];b[17]=a[14];b[8]=a[19];b[7]=a[17];b[22]=a[8];b[24]=a[7];b[13]=a[22];b[14]=a[24];
}

bool Judge()
{
    init();
    swap1();
    if(cube())
        return true; 
    
    init();
    swap2();
    if(cube())
        return true;

    init();    
    swap3();
    if(cube())
        return true;
        
    init();
    swap4();
    if(cube())
        return true;
        
    init();
    swap5();
    if(cube())
        return true;
        
    init();
    swap6();
    if(cube())
        return true;
    return false;
}

bool judge_num()
{
    set<int>qq;
    for(int i=1;i<=24;i++)
        qq.insert(a[i]);
    if(qq.size()==6)
        return true;
    return false;
}

void input()
{
    for(int i=1;i<=24;i++)
        scanf("%d",&a[i]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        
        input();
        if(!judge_num())
        {
            puts("NO");
            continue;
        }
        
        init();
        if(cube())    
        {
            puts("YES");
            continue;
        }
        if(Judge())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
