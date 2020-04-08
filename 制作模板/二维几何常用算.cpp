///计算凸包，输入点数组p，个数为p，输出点数组ch。函数返回凸包定点数
///输入不能有重复的点。函数执行完之后输入点的顺序被破坏。
///如果不希望在凸包的边上有输入点，吧两个<=改成<
///在精度要求高的时候用dcmp比较
int ConvexHull(Point* p, int n, Point* ch){
    sort(p, p+n);
    int m = 0;
    for (int i=0; i<n; i++) {
        while (m>1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0)m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i=n-2; i>=0; i--) {
        while (m>k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0)m--;
        ch[m++] = p[i];
    }
    if (n>1)m--;
    return m;
}


typedef vector<Point> Polygon; ///多边形的定义
///判断点是否在多边形内。
///在边界上返回-1，在内部返回1，在外部返回0
int isPointInPloygon(Point p,Polygon poly){
    int wn = 0 ;
    int n = poly.size() ;
    for(int i=0;i<n;i++){
        if(isPointOnsegment(p,poly[i],poly[(i+1)%n]))return -1 ;///在边界上
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i])) ;
        int d1 = dcmp(poly[i].y-p.y) ;
        int d2 = dcmp(poly[(i+1)%n].y-p.y) ;
        if(k>0&&d1<=0&&d2>0)wn++ ;
        if(k<0&&d2<=0&&d1>0)wn-- ;
    }
    if(wn!=0)return 1 ;
    return 0;
}
