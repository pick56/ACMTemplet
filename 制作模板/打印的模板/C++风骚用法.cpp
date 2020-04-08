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
///对s进行遍历
int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();
///多个vector、数组，之间的赋值
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
qq.resize(20) ;///扩充到20个
qq.resize(20,2) ;///扩充到20个，同时新值为第二个参数
for(int i=0;i<qq.size();i++){///复杂度是n^2想想为什么，一般不能这么写
    printf("%d ",qq[i]);///下标访问，和指针访问的复杂度都是一样的
}

struct node{
    int a,b,c ;
};
(node){1,2,3} ; ///就这样直接初始化一个结构体，构造器简直太low了
