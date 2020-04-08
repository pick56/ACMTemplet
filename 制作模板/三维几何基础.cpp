///��ά���λ���
#include<bits/stdc++.h>
using namespace std ;
struct Point3{
    double x,y,z;
    Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
};
typedef Point3 Vector3 ;
Vector3 operator + (Vector3 A,Vector3 B){
    return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);
}
Vector3 operator - (Vector3 A,Vector3 B){
    return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);
}
Vector3 operator * (Vector3 A,double p){
    return Vector3(A.x*p,A.y*p,A.z*p);
}
Vector3 operator / (Vector3 A,double p){
    return Vector3(A.x/p,A.y/p,A.z/p);
}
bool operator == (const Point3& a,const Point3& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0&&dcmp(a.z-b.z)==0;
}

///������gcd
double gcd(double x,double y){return dcmp(y)==0?x:gcd(y,fmod(x,y));}
double Dot(Vector3 A,Vector3 B){return A.x*B.x+A.y*B.y+A.z*B.z ;}
double Length(Vector3 A){return sqrt(Dot(A,A));}
double Angle(Vector3 A,Vector3 B){return acos(Dot(A,B)/Length(A)/Length(B)) ;}
///��p��ƽ��p0-n�ľ��룬n����Ϊ��λ����&&��ƽ��ķ�������p0��ƽ���ϡ�
double DistanceToPlane(const Point3& p,const Point3& p0,const Vector3& n){return fabs(Dot(p-p0,n));}
///��p��ƽ��p0-n�ϵ�ͶӰ��n����Ϊ��λ����
Point3 GetPlaneProjection(const Point3& p,const Point3& p0,const Vector3& n){return p-n*Dot(p-p0,n);}
///ֱ��p1-p2��ƽ��p0-n�Ľ��㡣���轻��Ψһ���ڣ�������
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p0,Vector3 n){
    Vector3 v = p2-p1 ;
    double t = (Dot(n,p0-p1)/Dot(n,p2-p1)) ;///�жϷ�ĸ�Ƿ�Ϊ0
    return p1+v*t ;///������߶Σ��ж�t�ǲ�����0��1֮��
}
///�����Ĳ������������A������Bƽ�н��Ϊ0
Vector3 Cross(Vector3 A,Vector3 B){
    return Vector3(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x) ;
}
double Area2(Point3 A,Point3 B,Point3 C){return Length(Cross(B-A,C-A)) ;}
///�жϵ�p�Ƿ���������p1p2p3��
bool PointInTri(Point3 p,Point3 p0,Point3 p1,Point3 p2){
    double area1 = Area2(p,p0,p1) ;
    double area2 = Area2(p,p1,p2) ;
    double area3 = Area2(p,p2,p0) ;
    return dcmp(area1+area2+area3-Area2(p0,p1,p2))==0 ;///dcmp��������ǰ����
}
///������p0p1p2�Ƿ���߶�AB�ཻ
bool TriSegIntersection(Point3 p0,Point3 p1,Point3 p2,Point3 A,Point3 B,Point3& p){
    Vector3 n = Cross(p1-p0,p2-p0) ;
    if(dcmp(Dot(n,B-A))==0)return false ;///�߶�AB��ƽ��p0p1p2ƽ�л���
    else{///ƽ��A��p1-p2��Ψһ����
        double t = Dot(n,p0-A)/Dot(n,B-A) ;
        if(dcmp(t)<0||dcmp(t-1)>0)return false ;///���㲻��AB��
        p=A+(B-A)*t ;///���㽻��
        return PointInTri(p,p0,p1,p2);///�жϽ����Ƿ���������p0-p1-p2��
    }
}
///��p��ֱ��AB�ľ���
double DistanceToLine(Point3 p,Point3 A,Point3 B){
    Vector3 v1 = B-A;
    Vector3 v2 = p-A;
    return Length(Cross(v1,v2)) /Length(v1) ;
}
///��p���߶�AB�ľ���
double DistanceToSegment(Point3 p,Point3 A,Point3 B){
    if(A==B)return Length(p-A) ;
    Vector3 v1 = B-A ;
    Vector3 v2 = p-A ;
    Vector3 v3 = p-B ;
    if(dcmp(Dot(v1,v2))<0)return Length(v2) ;
    else if(dcmp(Dot(v1,v3))>0)return Length(v3) ;
    else return Length(Cross(v1,v2))/Length(v1) ;
}
///����AB��AC��AD�Ļ�ϻ�����Ҳ����������ABCD�����������6��
double Volume6(Point3 A,Point3 B,Point3 C,Point3 D){
    return Dot(D-A,Cross(B-A,C-A)) ;
}
///��ά͹��������ά�ռ��ڵ�һЩ�㣬�������ǵ���С͹�������Ϊ��Щ���͹��
struct Face{
    int v[3] ;
    Vector3 normal(Point3 *P) const {
        return Cross(P[v[1]]-P[v[0]],P[v[2]]-P[v[0]]);
    }
    int cansee(Point3* P,int i)const {
        return Dot(P[i]-P[v[0]],normal(P)) > 0 ? 1 : 0 ;
    }
};
///����������λ͹��
///û�п��Ǹ���������������ĵ㹲�棩��ʵ���У����ڵ���ǰ����������΢С�Ŷ�
vector<Face>CH3D(Point3* p,int n){
    vector<Face>cur ;
    ///�����Ѿ������Ŷ���ǰ�����㲻����
    cur.push_back(Face{{0,1,2}}) ;
    cur.push_back(Face{{2,1,0}}) ;
    for(int i=3;i<n;i++){
        vector<Face>Next ;
        ///����ÿ���ߡ����桱�Ŀɼ���
        for(int j=0;j<cur.size();j++){
            Face f = cur[j] ;
            int res = f.cansee(p,i) ;
            if(!res)Next.push_back(f) ;
            for(int k=0;k<3;k++)vis[f.v[k]][f.v[(k+1)%3]] = res ;
        }
        for(int j=0;j<cur.size();j++){
            for(int k=0;k<3;k++){
                int a=cur[j].v[k];
                int b=cur[j].v[(k+1)%3] ;
                if(vis[a][b]!=vis[b][a]&&vis[a][b])
                Next.push_back((Face){{a,b,i}}) ;
            }
        }
        cur = Next ;
    }
    return cur ;
}
double rand01(){return rand()/(double)RAND_MAX ;}///0-1�������
double randeps(){return (rand01()-0.5)*eps ;}///-eps/2��eps/2�������
Point3 add_noise(Point3 p){
    return Point3(p.x+randeps(),p.y+randeps(),p.z+randeps()) ;
}


