///给一堆单词，获得每一个单词的最佳缩写
///样例输入就是那些单词
///样例输出-最佳前缀
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxnode = 1000 * 30;///构建树的所有字母
const int sigma_size = 30;///出现的字符种类
char data[1005][30] ;
struct Trie {
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int num[maxnode];
    int sz;
    void clear(){
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(num, 0, sizeof(num));
    }
    int idx(char c) { return c - 'a'; }///字符到数字转换
    void insert(const char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if(!ch[u][c]) {///如果没有节点，那就扩展一个节点
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                num[sz] = 0 ;
                ch[u][c] = sz++;///扩展节点编号增加
            }
            u = ch[u][c];
            num[u]++ ;
        }
        val[u] = v;
    }
    void find(char *s,int x){///寻找字符串s
        int u = 0;
        int p = 0;
        for(int i = 0; i < strlen(s); i++) {
            if(s[i] == '\0'||num[u]==1)break;
            int c = idx(s[i]);
            u = ch[u][c];
            p++ ;
        }
        for(int i=0;i<p;i++){
            printf("%c",s[i]);
        }printf("\n");
    }
};
char str[maxnode] ;
Trie trie;
int main() {
    int c = 1 ;
    trie.clear();
    while(~scanf("%s",str)){
        trie.insert(str, c);
        strcpy(data[c++],str) ;
    }
    for(int i=1;i<=c;i++){
        printf("%s ",data[i]);
        trie.find(data[i],i);
    }
    return 0;
}
//carbohydrate carboh
//cart cart
//carburetor carbu
//caramel cara
//caribou cari
//carbonic carboni
//cartilage carti
//carbon carbon
//carriage carr
//carton carto
//car car
//carbonate carbona
