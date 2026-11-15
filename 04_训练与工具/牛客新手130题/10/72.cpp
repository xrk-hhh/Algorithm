// #include <bits/stdc++.h>
// using namespace std;

// struct point{
//     double x,y;
//     point(double A,double B){
//         x=A,y=B;
//     }
//     point() = default;
// };

// struct line{
//     point point_A,point_B;
//     line(point A,point B){
//         point_A = A,point_B = B;
//     }
//     line() = default;
// };

// double getDistance(point P, line L){
//     // TODO: 计算点P到直线L的距离
//     double xx = P.x, yy = P.y;
//     double x1 = L.point_A.x, y1 = L.point_A.y;
//     double x2 = L.point_B.x, y2 = L.point_B.y;

//     double A = y1 - y2;
//     double B = -(x1 - x2);
//     double C = -(y1 * x2 - y2 * x1);

//     double dis = fabs(A * xx + B * yy + C) / sqrt(A * A + B * B);
    
//     return dis;
// }

// int main(){
//     int a, b, sx, sy, tx, ty;
//     cin >> a >> b >> sx >> sy >> tx >> ty;
//     point A(sx, sy), B(tx, ty), C(a, b);
//     line L(A, B);
//     printf("%.2lf", getDistance(C, L));
//     return 0;
// }