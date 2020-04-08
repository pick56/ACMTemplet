/**
���⣺
������������T
�������Ǹ���S�������ׯ����P��Ȼ������P����ׯ�����ꡣ
���ǵ����þ�����������ׯ�������Ӿ����ͨѶ��*��x����ׯͨ����Ҫx�����ǣ�
������Ϊ�������д�ׯͨ�ţ��������ǵ���С��������ׯ���롣
����˼·��
ֱ��500����ׯ����ȫͼ�ı����ں���Χ�ڣ��������ÿ������ׯ�ľ���
��һ����С��������ע�������С�������ӱ߼ӵ�n-s�͹��ˣ�����Ǹ��߾Ϳ����ˡ�
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
