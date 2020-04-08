///����һ���Գƾ��󣬱�ʾi��j�ľ��룬��������С������
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005 ;
const int INF = 0x3f3f3f3f ;
int pa[maxn] ;
int mapp[105][105] ;
int n,m;
int findset(int x){///���鼯
    return pa[x]!=x?pa[x]=findset(pa[x]):x ;
}
struct Edge{ ///���
    int u,v,d ;
    Edge(int u,int v,int d):u(u),v(v),d(d){}
    bool operator < (const Edge& p)const {///���ձߴ�С��������
        return d<p.d ;
    }
};
vector<Edge>e;
int kruskal(){
    int ans = INF ;
    int ret = 0 ;
    int cnt = 0 ;
    for(int i=1;i<=n;i++)pa[i]=i ;
    for(int i=0;i<m;i++){
        int u=findset(e[i].u) ;
        int v=findset(e[i].v) ;
        if(u!=v){
            pa[v]=u ;
            cnt++ ;
            ret += e[i].d;
            if(cnt==n-1)break ;
        }
    }
    return ret ;
}

int main(){
    while(~scanf("%d",&n)){
        e.clear();///��ձ߼�
        m=n*(n-1)/2 ;///���󲻰������Խ����ϣ�һ����n*n-n��/2���ߡ�
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int a ;
                scanf("%d",&a);
                if(i>j)e.push_back(Edge(i,j,a));
            }
        }
		sort(e.begin(),e.end()) ;//�мǸ�����Ϊ���ȶ�������ȱ�ÿ������һ��
        printf("%d\n",kruskal());
    }
    return 0;
}
