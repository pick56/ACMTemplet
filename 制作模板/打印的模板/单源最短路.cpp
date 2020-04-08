///单源最短路，没有判断负环
///边权可以为负数
///复杂度nlogn
#include<bits/stdc++.h>
using namespace std;
struct Edge{///边的起点，终点，和长度
    int from,to,dist;
};
struct HeapNode{///优先队列的结点
    int d,u ;///s到u当前最短的距离为d
    bool operator < (const HeapNode& rhs) const{
        return d>rhs.d ;
    }
};
const int maxn = 200005 ;
const int INF = 0x3f3f3f3f ;
int n,m;///点数和边数
vector<Edge> edges ;///边列表
vector<int> G[maxn] ;///每个结点出发的边编号
bool done[maxn] ;///是否已永久标号
int d[maxn] ;///s到各个点的距离
int p[maxn] ;///最短路中的上一条边
void init(){
    for(int i=0;i<n;i++)G[i].clear() ;///清空邻接表
    edges.clear() ;///清空边表
}
void AddEdge(int from,int to,int dist){///如果是无向图，每条边需要调用两次AddEdge
    edges.push_back((Edge){from,to,dist}) ;
    int mm = edges.size() ;
    G[from].push_back(mm-1) ;
}
void Dijkstra(int s){///求s到所有点的距离
    priority_queue<HeapNode> Q ;
    for(int i=0;i<n;i++)d[i] = INF ;
    d[s]=0;
    memset(done,0,sizeof(done)) ;
    Q.push((HeapNode){0,s}) ;
    while(!Q.empty()){
        HeapNode x = Q.top() ;
        Q.pop() ;
        int u = x.u ;
        if(done[u])continue ;///如果判断负环的话，这里可以看u点出队列多少次
        done[u] = true ;
        for(int i=0;i<G[u].size();i++){///遍历该点相连的每条边
            Edge& e = edges[G[u][i]] ;
            if(d[e.to]>d[u]+e.dist){///如果更短则更新
                d[e.to] = d[u] + e.dist ;
                p[e.to] = G[u][i] ;
                Q.push((HeapNode){d[e.to],e.to}) ;
            }
        }
    }
}
int main(){
    while(cin>>n>>m){
        init() ;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c ;a--;b--;
            AddEdge(a,b,c) ;
        }
        Dijkstra(0) ;///此算法点的编号从0开始
        for(int i=1;i<n;i++)cout<<d[i]<<endl;
    }
    return 0;
}

// 算法训练 最短路
//时间限制：1.0s   内存限制：256.0MB
//提交此题   锦囊1   锦囊2
//问题描述
//给定一个n个顶点，m条边的有向图（其中某些边权可能为负，但保证没有负环）。请你计算从1号点到其他点的最短路（顶点从1到n编号）。
//
//输入格式
//第一行两个整数n, m。
//
//接下来的m行，每行有三个整数u, v, l，表示u到v有一条长度为l的边。
//
//输出格式
//共n-1行，第i行表示1号点到i+1号点的最短路。
//样例输入
//3 3
//1 2 -1
//2 3 -1
//3 1 2
//样例输出
//-1
//-2
//数据规模与约定
//对于10%的数据，n = 2，m = 2。
//
//对于30%的数据，n <= 5，m <= 10。
//
//对于100%的数据，1 <= n <= 20000，1 <= m <= 200000，-10000 <= l <= 10000，保证从任意顶点都能到达其他所有顶点。
