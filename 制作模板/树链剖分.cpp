#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL ;
const int N = 50005 ;
int n,tim;
int sz[N];
int deep[N];
int top[N];
int son[N];
int fa[N] ;
int Rank[N] ;
int dfn[N] ;
int mk[N<<2] ;
int d[N] ;
vector<int>G[N] ;
void DFS1(int u){
    sz[u] = 1 ;
    son[u] = 0 ;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i] ;
        if(v!=fa[u]){
            fa[v] = u ;
            deep[v] = deep[u] + 1 ;
            DFS1(v) ;
            if(!son[u]||sz[v]>sz[son[u]])son[u] = v ;
            sz[u]+=sz[v] ;
        }
    }
}
void DFS2(int u,int tp){
    top[u] = tp ;
    dfn[u] = ++tim ;
    Rank[tim] = u ;
    if(!son[u])return ;
    DFS2(son[u],tp) ;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i] ;
        if(v!=son[u]&&v!=fa[u])DFS2(v,v) ;
    }
}
void build(int l,int r,int rt){
    mk[rt] = 0 ;
    if(l==r){
        mk[rt] = d[Rank[l]] ;
        return ;
    }
    int m = (l+r)>>1 ;
    build(lson);
    build(rson);
}
int query(int pos,int l,int r,int rt){
    if(l==r)return mk[rt] ;
    int m = (l+r)>>1 ;
    int ret = mk[rt] ;
    if(pos<=m)ret+=query(pos,lson) ;
    else ret+=query(pos,rson) ;
    return ret ;
}
void update(int L,int R,int a,int l,int r,int rt){
    if(L<=l&&r<=R){
        mk[rt]+=a ;
        return ;
    }
    int m = (l+r)>>1 ;
    if(L<=m)update(L,R,a,lson) ;
    if(R>m)update(L,R,a,rson) ;
}
void change(int L,int R,int c){
    while(top[L]!=top[R]){
        if(deep[top[L]]<deep[top[R]])swap(L,R) ;
        update(dfn[top[L]],dfn[L],c,1,n,1) ;
        L = fa[top[L]] ;
    }
    if(deep[L]>deep[R])swap(L,R) ;
    update(dfn[L],dfn[R],c,1,n,1) ;
}
int main(){
    int n,m,k;///nµãm±ßk²Ù×÷
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(int i=1;i<=n;i++){
            scanf("%d",d+i);
            G[i].clear() ;
        }
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b) ;
            G[b].push_back(a) ;
        }
        deep[1] = 0 ;
        fa[1] =  0 ;
        DFS1(1) ;
        tim = 0 ;
        DFS2(1,1) ;
        build(1,n,1) ;
        char op[3] ;
        while(k--){
            int a,b,c;
            scanf("%s",op) ;
            if(op[0]=='Q'){
                scanf("%d",&a) ;
                printf("%d\n",query(dfn[a],1,n,1));
            }else{
                scanf("%d%d%d",&a,&b,&c) ;
                if(op[0]=='D')c = -c ;
                change(a,b,c) ;
            }
        }
    }
}
