///扩展kmp
///主要的就是Next数组
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 200005;
int Next[N];
void getNext(char *T) {
    int i,length = strlen(T);
    Next[0] = length;
    for(i = 0; i<length-1 && T[i]==T[i+1]; i++);
    Next[1] = i;
    int a = 1;
    for(int k = 2; k < length; k++) {
        int p = a+Next[a]-1, L = Next[k-a];
        if((k-1)+L>=p) {
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<length && T[k+j]==T[j]) j++;
            Next[k] = j, a = k;
        } else Next[k] = L;
    }
}
int main() {
    int T ;
    char t[N];
    int n ;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%s",&n,t); ///文本串 和 模板串
        getNext(t);
        int ans = 0 ;
        for(int i=0;i<n;i++){
            ans=(ans+Next[i])%10007 ;
        }
        printf("%d\n",ans%10007);
    }
    return 0;
}
