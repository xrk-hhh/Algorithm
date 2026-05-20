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

// struct Circle{
//     point O;
//     int r;
//     Circle(point A,int B){
//         O=A,r=B;
//     }
//     Circle() = default;
// };

// double getDistance(const Circle& circle, const line& l) {
//     // 请在这里实现你的代码
//     double xx = circle.O.x, yy = circle.O.y;
//     int rr = circle.r;
//     double x1 = l.point_A.x, y1 = l.point_A.y;
//     double x2 = l.point_B.x, y2 = l.point_B.y;

//     double A = y1 - y2;
//     double B = -(x1 - x2);
//     double C = -(y1 * x2 - y2 * x1);

//     double dis = fabs(A * xx + B * yy + C) / sqrt(A * A + B * B);

//     double ans = sqrt(rr * rr - dis * dis) * 2;
    
//     return ans;
// }

// int main() {
//     double ox, oy, r;
//     double x1, y1, x2, y2;
    
//     cin >> ox >> oy >> r;
//     cin >> x1 >> y1 >> x2 >> y2;
    
//     point center(ox, oy);
//     Circle circle(center, (int)r);
    
//     point p1(x1, y1);
//     point p2(x2, y2);
//     line l(p1, p2);
    
//     double result = getDistance(circle, l);
//     cout << fixed << setprecision(6) << result << endl;
    
//     return 0;
// }