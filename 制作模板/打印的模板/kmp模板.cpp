///kmp模板
///模式串在文本串中出现了多少次
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005 ;

int f[maxn] ;
int ans =0 ;
void find(char *T,char *P){
    int n = strlen(T);
    int m = strlen(P) ;
    int j = 0 ;
    for(int i=0;i<n;i++){
        while(j&&P[j]!=T[i])j = f[j] ;
        if(P[j]==T[i])j++ ;
        if(j==m){
            ans++ ;
            j = 0 ;
        }
    }
}
void getfail(char *p){
    int m = strlen(p) ;
    f[0] = 0 ;
    f[1] = 0 ;
    for(int i=1;i<m;i++){
        int j = f[i] ;
        while(j&&p[i]!=p[j])j = f[j] ;
        f[i+1] = (p[i]==p[j] ? j+1 : 0) ;
    }
}
char str[maxn] ;
char p[maxn] ;
int main(){
    while(~scanf("%s",str)){
        ans = 0 ;
        if(str[0]=='#')break ;
        scanf("%s",p);
        getfail(p);
        find(str,p) ;
        printf("%d\n",ans);
    }
    return 0;
}
