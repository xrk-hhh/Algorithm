// #include <bits/stdc++.h>
// using namespace std;

// struct point{
//     double x,y;
//     point(double A,double B){
//         x=A,y=B;
//     }
//     point() = default;
// };

// struct triangle{
//     point a,b,c;
//     triangle(point A,point B,point C){
//         a=A,b=B,c=C;
//     }
//     triangle() = default;
// };

// double getArea(triangle T){
//     // TODO: 计算三角形T的面积
//     double x1 = T.a.x, y1 = T.a.y;
//     double x2 = T.b.x, y2 = T.b.y;
//     double x3 = T.c.x, y3 = T.c.y;

//     double l1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1- y2));
//     double l2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1- y3));
//     double l3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2- y3));

//     double p = (l1 + l2 + l3) / 2.0;

//     double S = sqrt(p * (p - l1) * (p - l2) * (p - l3));
//     return S;
// }

// int main(){
//     int x, y;
//     cin >> x >> y;
//     point a(x, y);
//     cin >> x >> y;
//     point b(x, y);
//     cin >> x >> y;
//     point c(x, y);
//     triangle T(a, b, c);
//     cout << fixed << setprecision(2) << getArea(T) << endl;
//     return 0;
// }