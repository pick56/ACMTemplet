///���ģ�����⣺����һ���ַ������������Ƚ��ܹ���Ҫ�Ƚ��ַ��ĸ���
///�����м�ֵ����trie��insert���֣�������Ե���ģ������,ע��longlong
#include<bits/stdc++.h>
using namespace std;
const int maxnode = 4000*1000 +10;
struct Trie{
    int head[maxnode] ;///��i���ڵ������ӱ��
    int next[maxnode] ;///��i���ڵ�����ֵܱ��
    int tot[maxnode] ;///ÿһ���ڵ��
    char ch[maxnode] ;///��i���ڵ��Ϊ����������Ҷ�ڵ�����
    int sz ;///�ڵ�����
    long long ans = 0 ;///����
    void clear(){
        sz = 1 ;
        head[0] = next[0] = tot[0] = 0 ;
    }
    void insert(const char *s){///��׼�Ľ�������
        int u = 0 ,v,n = strlen(s);
        tot[0]++ ;
        for(int i=0;i<=n;i++){///�������
            bool found = false ;
            for(v = head[u];v!=0;v=next[v]){///���ֵܽڵ�
                if(ch[v]==s[i]){
                    found = true ;
                    break ;
                }
            }
            if(!found){
                v = sz++ ;///�½��ڵ�
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
    void dfs(int depth,int u){ ///ͳ������
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
