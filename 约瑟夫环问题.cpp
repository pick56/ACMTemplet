/**
Լɪ�����⣬
��֪n���ˣ��Ա��0��2��3...n-1�ֱ��ʾ��Χ����һ�𡣴ӱ��Ϊ0���˿�ʼ����������k���Ǹ��˳��У�
������һ�����ִ�1��ʼ����������k���Ǹ����ֳ��У�
���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����У����һ�����е���Ϊʤ���ߡ�
��ʤ���߱��.

�������⣺
n,m��ʾn����«�ޣ�����m����
ÿ���˶���һ��Ȩ��w[i]����ÿ���˿�ʼ�ĸ���Ϊw[i]/sum(w[i])
ÿ���˶���һ��a[i]�������Ǻ��˻��ǻ���
�������˻������ĸ���
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005 ;
int a[maxn],w[maxn] ;
int b[maxn] ;
int cal(int m,int k){
    // m���ˣ���k����
    if(m<=0||k<=0){
        printf("impossble!");
        return -1;
    }else{
        if(m==1){
            return 0;
        }else{
            return ((cal(m-1,k)+k)%m);
        }
    }
}
int main(){
//    printf("%d\n",cal(3,2));

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]) ;
    }
    double sum = 0 ;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]) ;
        sum+=w[i] ;
    }
    int id = cal(n,m) ;
    double ans = 0.0 ;
    for(int i=0;i<n;i++){
        ans+=w[i]/sum*a[(i+id)%n] ;
    }
    printf("%f\n",ans) ;
    return 0 ;
}
/*
3 2
0 0 1
2 1 1
*/
