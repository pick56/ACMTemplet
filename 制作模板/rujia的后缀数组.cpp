#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10000 ;


char s[maxn] ;///�����ַ���s
//int s[maxn] ;///�����ַ���s
int sa[maxn];///�ĸ������ռ�
int t[maxn] ;
int t2[maxn] ;
int c[maxn] ;
int n;
///�����ַ���s�ĺ������顣ÿ���ַ���ֵ����Ϊ0~m-1
void build_sa(int m){
    int i;
    int *x = t ;
    int *y = t2 ;
    ///��������
    for(i=0;i<m;i++)c[i] = 0 ;///��ʼ��
    for(i=0;i<n;i++)c[x[i]=s[i]]++ ;///��Ӧλ�����

//    for(i='a';i<='z';i++){
//        printf("%d ",c[i]);
//    }printf("\n");

    for(i=1;i<m;i++)c[i]+=c[i-1];///һ���򵥵��ۼ�

//    for(i='a';i<='z';i++){
//        printf("%d ",c[i]);
//    }printf("\n");


    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i ;

    for(i=0;i<n;i++){
        printf("%d ",sa[i]);
    }printf("\n");

    for(int k=1;k<=n;k<<=1){
        int p = 0 ;
        ///ֱ������sa��������ڶ��ؼ���
        for(i=n-k;i<n;i++)y[p++] = i ;


        for(i=0;i<n;i++){
            if(sa[i]>=k){
                y[p++] = sa[i]-k ;
            }
        }

        printf("y=\n");
        for(i=0;i<p;i++){
            printf("%d ",y[i]);
        }printf("\n");

        ///���������һ�ؼ���
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=0;i<m;i++)c[i]+=c[i-1] ;

        puts("c=");
        for(i='a';i<='z';i++){
            printf("%d ",c[i]);
        }printf("\n");


        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]] = y[i] ;

        puts("min");
        for(i=0;i<n;i++){
            printf("%d ",sa[i]);
        }printf("\n");

        ///����sa��y��������µ�x����
        swap(x,y) ;
        p=1;
        x[sa[0]] = 0 ;
        for(i = 1 ;i<n;i++){
            x[sa[i]] = (y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]) ? p-1 :p++ ;
        }
        if(p>=n)break ;
        m = p ;
    }
}
//int m ;
//int cmp_suffix(char* parttern,int p){
//    return strncmp(parttern,s+sa[p],m);
//}
//int find(char *P){
//    m = strlen(P);
//    if(cmp_suffix(P,0)<0)return -1;
//    if(cmp_suffix(P,n-1)>0)return -1;
//    int L=0,R=n-1 ;
//    while(R>=L){
//        int M = L+(R-L)/2 ;
//        int res = cmp_suffix(P,M);
//        if(!res)return M;
//        if(res<0)R = M-1 ;
//        else L = M+1 ;
//    }
//    return -1 ;
//}

int main(){
    //char st[maxn] ;
    freopen("in.txt","r",stdin);
    scanf("%s",s);
    n = strlen(s) ;
    build_sa('z'+1);
    for(int i=0;i<n;i++){
        printf("%d ",sa[i]);
    }
    printf("\n");
    return 0 ;
}
