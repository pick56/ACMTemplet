#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>qq;
    qq.resize(20);
    for(int i=0;i<qq.size();i++){
        printf("%d ",qq[i]);
    }

}
///set<int> s ;
///vector<int> v(s.begin(),s.end());
///��s���б���
int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();
///���vector�����飬֮��ĸ�ֵ
  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

vector<int>qq;
qq.push_back(24) ;
qq.resize(20) ;///���䵽20��
qq.resize(20,2) ;///���䵽20����ͬʱ��ֵΪ�ڶ�������
for(int i=0;i<qq.size();i++){///���Ӷ���n^2����Ϊʲô��һ�㲻����ôд
    printf("%d ",qq[i]);///�±���ʣ���ָ����ʵĸ��Ӷȶ���һ����
}

struct node{
    int a,b,c ;
};
(node){1,2,3} ; ///������ֱ�ӳ�ʼ��һ���ṹ�壬��������ֱ̫low��
