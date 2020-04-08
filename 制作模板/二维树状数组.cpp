///C����-�����������ϽǺ����½����꣬�������Ԫ�� 1��0 ��0 ��1��
///Q����-����ѯ�ʣ���ĳ�����Ƕ��١�
///�൱�ڴ����ţ�����ȡģ���ʣ�������ά��״�������log(n)��(0,0)-(x,y)�ĺ�
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1005 ;
int bit[maxn][maxn] ;
int n ;
int lowbit(int xx){return xx&-xx ;}
void add(int i,int j,int x){
    while(i<=n){
        int jj=j;
        while(jj<=n){
            bit[i][jj]+=x ;
            jj += lowbit(jj) ;
        }
        i+=  lowbit(i) ;
    }
}
int sum(int i,int j){
    int s = 0;
    while(i>0){
        int jj = j ;
        while(jj>0){
            s+=bit[i][jj] ;
            jj -= lowbit(jj) ;
        }
        i -= lowbit(i) ;
    }
    return s ;
}
int main(){
    int T ;
    scanf("%d",&T);
    while(T--){
        int t ;
        scanf("%d%d",&n,&t);
        char op[20] ;
        memset(bit,0,sizeof(bit)) ;
        for(int i=0;i<t;i++){
            scanf("%s",op) ;
            if(op[0]=='C'){
                int x,y,x1,y1 ;
                scanf("%d%d%d%d",&x,&y,&x1,&y1) ;
                add(x,y,1);
                add(x,y1+1,-1);
                add(x1+1,y,-1);
                add(x1+1,y1+1,1);
            }else if(op[0]=='Q'){
                int x,y ;
                scanf("%d%d",&x,&y) ;
                printf("%d\n",sum(x,y)%2) ;
            }
        }
        printf("\n") ;
    }
    return 0;
}
