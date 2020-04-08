//HDU 4347 ����n����t�β�ѯ��Ȼ����n���㣬Ȼ��ÿ�β�ѯ������m��һ����
//����������m����
#include<bits/stdc++.h>
using namespace std;
const int N=55555,K=5;
const int inf=0x3f3f3f3f;
#define sqr(x) (x)*(x)
int k,n,idx;   ///kΪά��,nΪ����
struct point {
    int x[K];
    bool operator < (const point &u) const {
        return x[idx]<u.x[idx];
    }
} po[N];
typedef pair<double,point> tp;///pair�������Ȱ���double��С�����ٰ���point����
priority_queue<tp>nq;
struct kdTree {
    point pt[N<<2];///���ϵ����нڵ�
    int son[N<<2];///���ϵ����нڵ㡢��¼����ÿ���ڵ�ļ���
    void build(int l,int r,int rt=1,int dep=0) {///Ĭ�ϲ���
        if(l>r) return;///�߽�
        son[rt]=r-l;///son������Ƿ�Χ����-1
        son[rt*2]=son[rt*2+1]=-1;///��ʼ������ӡ��Ҷ���
        idx=dep%k;///����ά��ѭ����Ϊ����
        int mid=(l+r)/2;///�м�����ѡȡ��ѡ���ǵ�mid�����
        ///�������򣬵�mid�������mid��λ�ã�����С��ǰ�棬��������ں���
        ///[first,last),nth_element(array,array+m,array+n);
        nth_element(po+l,po+mid,po+r+1);
        pt[rt]=po[mid];///�ѵ�mid��ĵ��������
        build(l,mid-1,rt*2,dep+1);///�ݹ齨�������
        build(mid+1,r,rt*2+1,dep+1);///�ݹ齨���Ҷ���
    }
    void query(point p,int m,int rt=1,int dep=0) {///��ѯ��p�����m�����ڵĵ�
        if(son[rt]==-1) return;///�߽�
        tp nd(0,pt[rt]);///pair�Ĺ�����
        ///����ֽ�Ľڵ㵽p��ľ���
        for(int i=0;i<k;i++)nd.first+=sqr(nd.second.x[i]-p.x[i]);
        int dim=dep%k;
        int x=rt<<1,y=rt<<1|1,fg=0;
        ///���p��dimά����������ڵ��ڸ��ڵ��ֵ
        if(p.x[dim]>=pt[rt].x[dim])swap(x,y);
        ///����ж���
        if(son[x]!=-1) query(p,m,x,dep+1);
        if(nq.size()<m) {///�������ĵ������С��m
            nq.push(nd),fg=1;///�Ž�ȥ
        } else {
            if(nd.first<nq.top().first) {///����ڵ�С����������
                nq.pop();///����֮
                nq.push(nd);
            }
            ///�����dimά���ϵĲ�С������ģ�����Ϊ����һ�����ڷ�֧�п����и����ĵ�
            if(sqr(p.x[dim]-pt[rt].x[dim])<nq.top().first) fg=1;
        }
        ///����ж��ӣ����ұ���Ϊ���и����������֮
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
        kd.build(0,n-1); ///����kd��
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
