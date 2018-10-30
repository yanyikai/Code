#include<cstring>
namespace SAM{
	#define N 2000005
	int tot,las,pre[N<<1],len[N<<1],siz[N],id[N],c[N],nex[N<<1][26];
	inline void Ins(int c)
	{
		int p=las,np=las=++tot;len[np]=len[p]+1;
		for(;!nex[p][c];p=pre[p])nex[p][c]=np;
		if(!p)pre[np]=1;
		else
		{
			int q=nex[p][c];
			if(len[p]+1==len[q])pre[np]=q;
			else
			{
				int nq=++tot;len[nq]=len[p]+1;
				memcpy(nex[nq],nex[q],sizeof nex[q]);
				pre[nq]=pre[q];pre[q]=pre[np]=nq;
				for(;nex[p][c]==q;p=pre[p])nex[p][c]=nq;
			}
		}
		siz[np]=1;
	}
	inline void Init(char*s)
	{
		las=tot=1;
		for(int i=0,n=strlen(s);i<n;++i)
			Ins(s[i]-'a');
		for(int i=1;i<=tot;++i)++c[len[i]];
		for(int i=1;i<=tot;++i)c[i]+=c[i-1];
		for(int i=1;i<=tot;++i)id[c[len[i]]--]=i;
	}
}using namespace SAM;
