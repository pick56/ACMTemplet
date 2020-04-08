///实现区间赋值
///范围极大值
#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 200005 ;
int maxv[maxn<<2] ;
int setv[maxn<<2] ;
int n,m;
void PushDown(int rt){
    setv[rt<<1|1]=setv[rt<<1] = setv[rt] ;
    if(setv[rt]>0){
        maxv[rt<<1|1] = maxv[rt<<1] = setv[rt<<1] ;
    }
}
void PushUp(int rt){
    maxv[rt] = max(maxv[rt<<1],maxv[rt<<1|1]) ;
}
void update(int L,int R,int s,int l,int r,int rt){
    if(L<=l&&r<=R){
        setv[rt] = s ;
        maxv[rt] = s ;
        return ;
    }
    //if(l==r)return ;
    PushDown(rt) ;
    int m = (r+l)>>1 ;
    if(L<=m)update(L,R,s,lson) ;
    if(R>m)update(L,R,s,rson) ;
    PushUp(rt) ;
}
int query(int L,int R,int l,int r,int rt){
    int ret = 0 ;
    if(L<=l&&r<=R){
        return max(ret,maxv[rt]) ;
    }
    //if(l==r)return 0;
    PushDown(rt) ;
    int m = (r+l)>>1 ;
    if(L<=m)ret = max(ret ,query(L,R,lson)) ;
    if(R>m)ret = max(ret ,query(L,R,rson)) ;
    return ret ;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(maxv,0,sizeof(maxv)) ;
        memset(setv,0,sizeof(setv)) ;
        for(int i=1;i<=n;i++){
            int a ;
            scanf("%d",&a);
            update(i,i,a,1,n,1) ;
        }
        char op[3] ;
        for(int i=0;i<m;i++){
            scanf("%s",op);
            if(op[0]=='U'){
                int a,b ;
                scanf("%d%d",&a,&b);
                update(a,a,b,1,n,1) ;
            }
            if(op[0]=='Q'){
                int a,b ;
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b,1,n,1)) ;
            }
        }
    }
    return 0;
}
