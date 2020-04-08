///����͹�������������p������Ϊp�����������ch����������͹��������
///���벻�����ظ��ĵ㡣����ִ����֮��������˳���ƻ���
///�����ϣ����͹���ı���������㣬������<=�ĳ�<
///�ھ���Ҫ��ߵ�ʱ����dcmp�Ƚ�
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


typedef vector<Point> Polygon; ///����εĶ���
///�жϵ��Ƿ��ڶ�����ڡ�
///�ڱ߽��Ϸ���-1�����ڲ�����1�����ⲿ����0
int isPointInPloygon(Point p,Polygon poly){
    int wn = 0 ;
    int n = poly.size() ;
    for(int i=0;i<n;i++){
        if(isPointOnsegment(p,poly[i],poly[(i+1)%n]))return -1 ;///�ڱ߽���
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i])) ;
        int d1 = dcmp(poly[i].y-p.y) ;
        int d2 = dcmp(poly[(i+1)%n].y-p.y) ;
        if(k>0&&d1<=0&&d2>0)wn++ ;
        if(k<0&&d2<=0&&d1>0)wn-- ;
    }
    if(wn!=0)return 1 ;
    return 0;
}
