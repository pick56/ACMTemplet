#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;///精度函数
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
const double PI = acos(-1);
struct Point { ///点
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
typedef Point Vector;///向量
struct Circle{///圆的定义
    Point c;
    double r ;
    Circle(Point c,double r):c(c),r(r){}///构造函数
    Point point(double a){///根据圆心角求圆上的坐标，返回一个点
        return Point(c.x+cos(a)*r,c.y+sin(a)*r) ;
    }
};


Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }
bool operator < (const Point& a, const Point& b) {return a.x < b.x || (a.x == b.x && a.y < b.y);}
bool operator == (const Point& a, const Point &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

///计算向量极角
double angle(Vector v){return atan2(v.y,v.x);}
///向量与x轴正方向的夹角（0-180）
double lineAngleDegree(Vector v) {
  double ang = angle(v)*180.0/PI;
  while(dcmp(ang) < 0) ang += 360.0;
  while(dcmp(ang-180) >= 0) ang -= 180.0;
  return ang;
}

Vector Rotate(Vector A, double rad) {///逆时针旋转rad
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal(Vector A) {///法向量的单位向量
  double L = Length(A);
  return Vector(-A.y/L, A.x/L);
}

struct Line {///点+向量构成直线
  Point p;
  Vector v;
  Line(Point p, Vector v):p(p),v(v) {}
  Point point(double t) {
    return p + v*t;
  }
  Line move(double d){///垂直方向移动d
    return Line(p + Normal(v)*d, v);
  }
};

///获得直线和圆的位置关系，sol没有清空，可以保存所有的直线与圆的交点。
int getLineCircleIntersection(Line L,Circle C,double& t1,double& t2,vector<Point>& sol){
    double a = L.v.x ;
    double b = L.p.x - C.c.x;
    double c = L.v.y;
    double d = L.p.y - C.c.y;
    double e = a*a+c*c ;
    double f = 2*(a*b+c*d) ;
    double g = b*b+d*d - C.r*C.r ;
    double delta = f*f -4*e*g ;///判别式
    if(dcmp(delta)<0) return 0 ;///相离
    if(dcmp(delta)==0){ ///相切
        t1 = t2 = -f / (2*e) ;
        sol.push_back(L.point(t1)) ;
        return 1 ;
    }
    ///相交
    t1 = (-f - sqrt(delta))/(2*e) ;
    sol.push_back(L.point(t1)) ;
    t2 = (-f + sqrt(delta))/(2*e) ;
    sol.push_back(L.point(t2)) ;
    return 2 ;
}

///两圆相交，交点在sol中，重合返回-1，一个交点返回1，两个交点返回2
int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point>& sol){
    double d=Length(C1.c-C2.c);
    if(dcmp(d)==0){
        if(dcmp(C1.r-C2.r)==0)return -1;
        return 0;
    }
    if(dcmp(C1.r+C2.r-d)<0)return 0;
    if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;
    double a=angle(C2.c-C1.c) ;
    double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
    Point p1=C1.point(a-da);
    Point p2=C1.point(a+da);
    sol.push_back(p1);
    if(p1==p2)return 1;
    sol.push_back(p2) ;
    return 2;
}
///过定点做圆的切线，v[i]表示的是第i条切线的向量，返回切线条数
int getTangents(Point p,Circle C,Vector* v){
    Vector u = C.c - p ;
    double dist = Length(u) ;
    if(dist<C.r)return 0;
    else if(dcmp(dist - C.r)==0){
        v[0] = Rotate(u,PI/2) ;
        return 1;
    }else{
        double ang = asin(C.r/dist) ;
        v[0] = Rotate(u,-ang) ;
        v[1] = Rotate(u,+ang) ;
        return 2 ;
    }
}
int getTangents(Circle A,Circle B,Point* a,Point* b){
    int cnt=0;
    if(A.r<B.r){
        swap(A,B);
        swap(a,b) ;
    }
    double d2 = (A.c.x-B.c.x)*(A.c.x-B.c.x) + (A.c.y-B.c.y)*(A.c.y-B.c.y) ;
    double rdiff = A.r-B.r ;
    double rsum = A.r+B.r ;
    if(d2<rdiff*rdiff)return 0;
    double base = atan2(B.c.y-A.c.y,B.c.x-A.c.x) ;
    if(d2==0&&A.r==B.r)return -1 ;
    if(d2==rdiff*rdiff){
        a[cnt] = A.point(base);
        b[cnt] = B.point(base);
        cnt++ ;
        return 1;
    }
    double ang = acos((A.r-B.r)/sqrt(d2)) ;
    a[cnt] = A.point(base+ang) ;
    b[cnt] = B.point(base+ang) ;
    cnt++ ;
    a[cnt] = A.point(base-ang) ;
    b[cnt] = B.point(base-ang) ;
    cnt++ ;
    if(d2==rsum*rsum){
        a[cnt] = A.point(base) ;
        b[cnt] = B.point(PI+base) ;
        cnt++ ;
    }else if(d2>rsum*rsum){
        double ang = acos((A.r+B.r)/sqrt(d2)) ;
        a[cnt] = A.point(base+ang) ;
        b[cnt] = B.point(PI+base+ang) ;
        cnt++ ;
        a[cnt] = A.point(base-ang) ;
        b[cnt] = B.point(PI+base-ang) ;
        cnt++ ;
    }
    return cnt ;
}

