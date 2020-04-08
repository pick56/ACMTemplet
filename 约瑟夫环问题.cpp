/**
约瑟夫环问题，
已知n个人（以编号0，2，3...n-1分别表示）围坐在一起。从编号为0的人开始报数，数到k的那个人出列；
他的下一个人又从1开始报数，数到k的那个人又出列；
依此规律重复下去，直到圆桌周围的人全部出列，最后一个出列的人为胜利者。
求胜利者编号.

本题题意：
n,m表示n个葫芦娃，按照m报数
每个人都有一个权重w[i]，从每个人开始的概率为w[i]/sum(w[i])
每个人都有一个a[i]代表它是好人还是坏人
求最后好人活下来的概率
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005 ;
int a[maxn],w[maxn] ;
int b[maxn] ;
int cal(int m,int k){
    // m个人，以k报数
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
