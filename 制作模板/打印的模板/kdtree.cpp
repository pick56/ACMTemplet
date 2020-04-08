//HDU 4347 输入n个点t次查询，然后是n个点，然后每次查询，输入m和一个点
//输出，最近的m个点
#include<bits/stdc++.h>
using namespace std;
const int N=55555,K=5;
const int inf=0x3f3f3f3f;
#define sqr(x) (x)*(x)
int k,n,idx;   ///k为维数,n为点数
struct point {
    int x[K];
    bool operator < (const point &u) const {
        return x[idx]<u.x[idx];
    }
} po[N];
typedef pair<double,point> tp;///pair，排序先按照double从小到大，再按照point的排
priority_queue<tp>nq;
struct kdTree {
    point pt[N<<2];///树上的所有节点
    int son[N<<2];///树上的所有节点、记录的是每个节点的极差
    void build(int l,int r,int rt=1,int dep=0) {///默认参数
        if(l>r) return;///边界
        son[rt]=r-l;///son保存的是范围差，跨度-1
        son[rt*2]=son[rt*2+1]=-1;///初始化左儿子、右儿子
        idx=dep%k;///按照维度循环作为划分
        int mid=(l+r)/2;///中间数的选取、选的是第mid大的数
        ///部分排序，第mid大的数在mid的位置，比它小的前面，比他大的在后面
        ///[first,last),nth_element(array,array+m,array+n);
        nth_element(po+l,po+mid,po+r+1);
        pt[rt]=po[mid];///把第mid大的点存在树中
        build(l,mid-1,rt*2,dep+1);///递归建立左儿子
        build(mid+1,r,rt*2+1,dep+1);///递归建立右儿子
    }
    void query(point p,int m,int rt=1,int dep=0) {///查询点p的最近m个相邻的点
        if(son[rt]==-1) return;///边界
        tp nd(0,pt[rt]);///pair的构造器
        ///计算分界的节点到p点的距离
        for(int i=0;i<k;i++)nd.first+=sqr(nd.second.x[i]-p.x[i]);
        int dim=dep%k;
        int x=rt<<1,y=rt<<1|1,fg=0;
        ///如果p在dim维度上坐标大于等于父节点的值
        if(p.x[dim]>=pt[rt].x[dim])swap(x,y);
        ///如果有儿子
        if(son[x]!=-1) query(p,m,x,dep+1);
        if(nq.size()<m) {///如果加入的点的数量小于m
            nq.push(nd),fg=1;///放进去
        } else {
            if(nd.first<nq.top().first) {///如果节点小于里面最大的
                nq.pop();///更新之
                nq.push(nd);
            }
            ///如果在dim维度上的差小于里面的，就认为另外一个相邻分支有可能有更近的点
            if(sqr(p.x[dim]-pt[rt].x[dim])<nq.top().first) fg=1;
        }
        ///如果有儿子，并且被认为是有更近的则查找之
        if(son[y]!=-1&&fg)query(p,m,y,dep+1);
    }
} kd;
void print(point &p) {
    for(int j=0; j<k; j++) printf("%d%c",p.x[j],j==k-1?'\n':' ');
}
int main() {
    while(scanf("%d%d",&n,&k)!=EOF) {
        for(int i=0; i<n; i++)
            for(int j=0; j<k; j++)
                scanf("%d",&po[i].x[j]);
        kd.build(0,n-1); ///建立kd树
        int t,m;
        scanf("%d",&t) ;
        while(t--) {
            point ask;
            for(int j=0; j<k; j++)scanf("%d",&ask.x[j]);
            scanf("%d",&m);
            kd.query(ask,m);
            printf("the closest %d points are:\n", m);
            point pt[20];
            for(int j=0; !nq.empty(); j++) {
                pt[j]=nq.top().second;
                nq.pop();
            }
            for(int j=m-1; j>=0; j--)print(pt[j]);
        }
    }
    return 0;
}
