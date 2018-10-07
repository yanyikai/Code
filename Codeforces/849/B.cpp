#include<bits/stdc++.h>  
using namespace std;  
int s[3000],n,p,i;  
bool if_line(double k)  
{  
    p=-1;  
    for(i=2;i<=n;i++)  
    {  
        if(s[i]-s[1]!=k*(i-1))
        {
        	if(p==-1) p=i;  
        	else
			{
				if(s[i]-s[p]!=k*(i-p))  return false; 
			} 
		} 
    }  
    return p!=-1;  
}  
int main()  
{  
    scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&s[i]);  
    if_line(s[2]-s[1])||if_line((s[3]-s[1])*0.5)||if_line(s[3]-s[2])?printf("Yes"):printf("No");    
}