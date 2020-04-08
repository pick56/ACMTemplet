/**
题意：
首先是样例数T
输入卫星个数S，输入村庄个数P，然后输入P个村庄的坐标。
卫星的作用就是让两个村庄可以无视距离的通讯，*（x个村庄通信需要x个卫星）
让你求为了让所有村庄通信，除了卫星的最小的两个村庄距离。
解题思路：
直接500个村庄，完全图的边数在合理范围内，所以求出每两个村庄的距离
跑一遍最小生成树，注意这个最小生成数加边加到n-s就够了，输出那个边就可以了。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005 ;
int s,p,n,m;
int u[maxn],v[maxn];
double w[maxn] ;
int xx[maxn],yy[maxn],pp[maxn],r[maxn];
int fid(int x){return pp[x]==x?x:pp[x]=fid(pp[x]);}
int cmp(const int i,const int j){return w[i]<w[j] ;}
double kruskal(){
    double ret =0;
    for(int i=0;i<n;i++)pp[i]=i;
    for(int i=0;i<m;i++)r[i]=i;
    sort(r,r+m,cmp) ;
    int cnt=0;
    for(int i=0;i<m;i++){
        if(cnt==n-s){
            break ;
        }
        int e = r[i] ;
        int x = fid(u[e]) ;
        int y = fid(v[e]) ;
        if(x!=y){
            pp[x]=y ;
            cnt++ ;
            ret = w[e] ;
        }
    }
    return ret ;

}
int main(){
    int t ;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&s,&p);
        n=p;
        for(int i=0;i<p;i++){
            scanf("%d%d",&xx[i],&yy[i]);
        }
        int c=0;
        for(int i=0;i<p;i++){
            for(int j=i+1;j<p;j++){
                u[c]=i;
                v[c]=j;
                w[c++]=sqrt(pow((double)(xx[i]-xx[j]),2)+pow((double)(yy[i]-yy[j]),2));
            }
        }
        m=c;
        double ans = kruskal() ;
        printf("%.2f\n",ans);
    }
    return 0;
}
