///这个模板题意：给你一堆字符串，求两两比较总共需要比较字符的个数
///代码有价值的是trie的insert部分，这里可以当作模板来做,注意longlong
#include<bits/stdc++.h>
using namespace std;
const int maxnode = 4000*1000 +10;
struct Trie{
    int head[maxnode] ;///第i个节点的左儿子编号
    int next[maxnode] ;///第i个节点的右兄弟编号
    int tot[maxnode] ;///每一个节点的
    char ch[maxnode] ;///第i个节点的为子数包含的叶节点总数
    int sz ;///节点总数
    long long ans = 0 ;///总数
    void clear(){
        sz = 1 ;
        head[0] = next[0] = tot[0] = 0 ;
    }
    void insert(const char *s){///标准的建树过程
        int u = 0 ,v,n = strlen(s);
        tot[0]++ ;
        for(int i=0;i<=n;i++){///逐个插入
            bool found = false ;
            for(v = head[u];v!=0;v=next[v]){///找兄弟节点
                if(ch[v]==s[i]){
                    found = true ;
                    break ;
                }
            }
            if(!found){
                v = sz++ ;///新建节点
                tot[v] = 0 ;
                ch[v] = s[i] ;
                next[v] = head[u] ;
                head[u] = v ;
                head[v] = 0 ;
            }
            u = v ;
            tot[u]++ ;
        }
    }
    void dfs(int depth,int u){ ///统计两两
        if(head[u]==0)ans+=tot[u]*(tot[u]-1)*depth ;
        else{
            int sum = 0 ;
            for(int v = head[u];v!=0;v = next[v])sum+=tot[v]*(tot[u]-tot[v]);
            ans += sum/2*(2*depth+1) ;
            for(int v = head[u];v!=0;v=next[v])dfs(depth+1,v);
        }
    }
    long long count(){
        ans = 0 ;
        dfs(0,0) ;
        return ans ;
    }
};
Trie trie ;char str[1005] ;int n ;
int main(){
    int cas = 1 ;
    while(~scanf("%d",&n)&&n){
        trie.clear();
        for(int i=0;i<n;i++){
            scanf("%s",str);
            trie.insert(str) ;
        }
        printf("Case %d: %lld\n",cas++,trie.count());
    }
    return 0;}
