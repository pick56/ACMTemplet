///最长回文子串
///HDU3086最长回文子序列的长度（manacher算法）
///给出一个只由小写英文字符a,b,c...y,z组成的字符串S,求S中最长回文串的长度.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 110005 ;
char str[2*maxn];
int p[2*maxn];
int main(){
    while(~scanf("%s",str)){
        int len = strlen(str);
        for(int i=len;i>=0;i--){
            str[2*i+2] = str[i] ;
            str[2*i+1] = '#' ;
        }
        str[0] = '*' ;
        puts(str);
        ///*#a#b#c#d#e#的字符串
        int id = 0 ;
        int maxlen = 0 ;
        memset(p,0,sizeof(p));
        for(int i = 2;i<2*len+1;i++){
            if(p[id]+id>i)p[i]=min(p[2*id-i],p[id]+id-i);
            else p[i] = 1 ;
            while(str[i-p[i]]==str[i+p[i]])p[i]++ ;
            if(id+p[id]<i+p[i])id = i ;
            if(maxlen<p[i])maxlen = p[i] ;
        }
        printf("%d\n",maxlen-1);
        ///输出的是最长回文子序列的长度
    }
    return 0;
}
