///区间和点的更新
///区间求和
///稍微修改一下就区间和点的设值
///再修改一下就是区间极值（添加两个数组）
#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 50005;
int n;
int sum[maxn<<2] ;
int addv[maxn<<2] ;
void PushUp(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1] ;
}
void PushDown(int rt){
    addv[rt<<1]+=addv[rt] ;
    addv[rt<<1|1]+=addv[rt] ;
}
void update(int L,int R,int add,int l,int r,int rt){
    if(L<=l&&r<=R){
        addv[rt] += add ;
        sum[rt]+=add*(r-l+1) ;
        return ;
    }
    if(l==r)return ;
    PushDown(rt) ;
    int m = (l+r)>>1 ;
    if(L<=m)update(L,R,add,lson);
    if(R>m)update(L,R,add,rson);
    PushUp(rt) ;
}
int query(int L,int R,int l,int r,int rt){
    int ret =0;
    if(L<=l&&r<=R){
        ret+=sum[rt];
        return ret;
    }
    if(l==r)return 0;
    int m = (l+r)>>1 ;
    if(L<=m)ret+=query(L,R,lson);
    if(R>m)ret+=query(L,R,rson);
    return ret ;
}
int main(){
    int T ,cas=1;
    scanf("%d",&T);
    while(T--){
        memset(sum,0,sizeof(sum));
        memset(addv,0,sizeof(addv));
        scanf("%d",&n);
        //build(1,n,1) ;
        for(int i=1;i<=n;i++){
            int a ;
            scanf("%d",&a);
            update(i,i,a,1,n,1) ;
        }
        printf("Case %d:\n",cas++);
        char op[10];
        while(scanf("%s",op)){
            if(op[0]=='E')break;
            if(op[0]=='A'){
                int a,b ;
                scanf("%d%d",&a,&b);
                update(a,a,b,1,n,1) ;
            }
            if(op[0]=='S'){
                int a,b ;
                scanf("%d%d",&a,&b);
                update(a,a,-b,1,n,1) ;
            }
            if(op[0]=='Q'){
                int a,b ;
                scanf("%d%d",&a,&b);
                int k = query(a,b,1,n,1) ;
                printf("%d\n",k) ;
            }
        }
    }
    return 0;
}
