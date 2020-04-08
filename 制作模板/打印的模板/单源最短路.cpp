///��Դ���·��û���жϸ���
///��Ȩ����Ϊ����
///���Ӷ�nlogn
#include<bits/stdc++.h>
using namespace std;
struct Edge{///�ߵ���㣬�յ㣬�ͳ���
    int from,to,dist;
};
struct HeapNode{///���ȶ��еĽ��
    int d,u ;///s��u��ǰ��̵ľ���Ϊd
    bool operator < (const HeapNode& rhs) const{
        return d>rhs.d ;
    }
};
const int maxn = 200005 ;
const int INF = 0x3f3f3f3f ;
int n,m;///�����ͱ���
vector<Edge> edges ;///���б�
vector<int> G[maxn] ;///ÿ���������ı߱��
bool done[maxn] ;///�Ƿ������ñ��
int d[maxn] ;///s��������ľ���
int p[maxn] ;///���·�е���һ����
void init(){
    for(int i=0;i<n;i++)G[i].clear() ;///����ڽӱ�
    edges.clear() ;///��ձ߱�
}
void AddEdge(int from,int to,int dist){///���������ͼ��ÿ������Ҫ��������AddEdge
    edges.push_back((Edge){from,to,dist}) ;
    int mm = edges.size() ;
    G[from].push_back(mm-1) ;
}
void Dijkstra(int s){///��s�����е�ľ���
    priority_queue<HeapNode> Q ;
    for(int i=0;i<n;i++)d[i] = INF ;
    d[s]=0;
    memset(done,0,sizeof(done)) ;
    Q.push((HeapNode){0,s}) ;
    while(!Q.empty()){
        HeapNode x = Q.top() ;
        Q.pop() ;
        int u = x.u ;
        if(done[u])continue ;///����жϸ����Ļ���������Կ�u������ж��ٴ�
        done[u] = true ;
        for(int i=0;i<G[u].size();i++){///�����õ�������ÿ����
            Edge& e = edges[G[u][i]] ;
            if(d[e.to]>d[u]+e.dist){///������������
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
        Dijkstra(0) ;///���㷨��ı�Ŵ�0��ʼ
        for(int i=1;i<n;i++)cout<<d[i]<<endl;
    }
    return 0;
}

// �㷨ѵ�� ���·
//ʱ�����ƣ�1.0s   �ڴ����ƣ�256.0MB
//�ύ����   ����1   ����2
//��������
//����һ��n�����㣬m���ߵ�����ͼ������ĳЩ��Ȩ����Ϊ��������֤û�и���������������1�ŵ㵽����������·�������1��n��ţ���
//
//�����ʽ
//��һ����������n, m��
//
//��������m�У�ÿ������������u, v, l����ʾu��v��һ������Ϊl�ıߡ�
//
//�����ʽ
//��n-1�У���i�б�ʾ1�ŵ㵽i+1�ŵ�����·��
//��������
//3 3
//1 2 -1
//2 3 -1
//3 1 2
//�������
//-1
//-2
//���ݹ�ģ��Լ��
//����10%�����ݣ�n = 2��m = 2��
//
//����30%�����ݣ�n <= 5��m <= 10��
//
//����100%�����ݣ�1 <= n <= 20000��1 <= m <= 200000��-10000 <= l <= 10000����֤�����ⶥ�㶼�ܵ����������ж��㡣
