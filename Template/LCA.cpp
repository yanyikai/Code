int fat[N],dep[N],dfn[N],pos[N],siz[N],son[N],top[N],tim;
vector<int>fir[N];
void dfs(int u){
    dep[u]=dep[fat[u]]+(siz[u]=1);
    for(int v:fir[u])if(v!=fat[u]){
        fat[v]=u,dfs(v),siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void DFS(int u){
    pos[dfn[u]=++tim]=u;
    if(son[u])top[son[u]]=top[u],DFS(son[u]);
    for(int v:fir[u])if(v!=fat[u]&&v!=son[u])
    DFS(top[v]=v);
}
int LCA(int x,int y){
    for(;top[x]^top[y];x=fat[top[x]])
        if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
    return dep[x]>dep[y]?y:x;
}