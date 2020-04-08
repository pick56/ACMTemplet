#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std ;
const int maxn = 5005 ;
char stra[maxn] ;
char strb[maxn] ;
int dp[2][maxn] ;
int main(){
    while(~scanf("%s%s",stra+1,strb+1)){
        stra[0]='#' ;
        strb[0]='#' ;
        int lena = strlen(stra) ;
        int lenb = strlen(strb) ;
        memset(dp,0,sizeof(dp)) ;
        for(int i=1;i<lena;i++){
            for(int j=1;j<lenb;j++){
                if(stra[i]==strb[j]){
                    dp[1][j] = dp[0][j-1]+1 ;
                }else{
                    dp[1][j] = max(dp[0][j],dp[1][j-1]) ;
                }
            }
            for(int j=0;j<lenb;j++){
                dp[0][j] = dp[1][j] ;
            }
        }
//        for(int i=0;i<lena;i++){
//            for(int j=0;j<lenb;j++){
//                printf("%d ",dp[i][j]) ;
//            }
//            printf("\n") ;
//        }
        printf("%d\n",dp[1][lenb-1]) ;
    }
    return 0;
}
