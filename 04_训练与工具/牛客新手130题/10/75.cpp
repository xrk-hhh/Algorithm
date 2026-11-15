// #include <bits/stdc++.h>
// using namespace std;

// struct point {
//     double x, y;
//     point(double A, double B) {
//         x = A, y = B;
//     }
//     point() = default;
// };

// struct line {
//     point point_A, point_B;
//     line(point A, point B) {
//         point_A = A, point_B = B;
//     }
//     line() = default;
// };

// point findMeetingPoint(line line_A, line line_B) {
//     // TODO: 在这里输入你的代码，求直线 line_A 与 line_B 的交点
//     double x1 = line_A.point_A.x, y1 = line_A.point_A.y;
//     double x2 = line_A.point_B.x, y2 = line_A.point_B.y;
//     double x3 = line_B.point_A.x, y3 = line_B.point_A.y;
//     double x4 = line_B.point_B.x, y4 = line_B.point_B.y;

//     double A1 = y1 - y2;
//     double B1 = -(x1 - x2);
//     double C1 = -(y1 * x2 - y2 * x1);
//     double A2 = y3 - y4;
//     double B2 = -(x3 - x4);
//     double C2 = -(y3 * x4 - y4 * x3);
    
//     point res;

//     if (fabs(A1 * B2 - A2 * B1)< 1E-9)
//     {
//         res.x = -1.0, res.y = -1.0;
//         return res;
//     }
//     else
//     {
//         double D = A1 * B2 - A2 * B1;
//         double D1 = B1 * C2 - B2 * C1;
//         double D2 = A2 * C1 - A1 * C2;
//         res.x = D1 / D;
//         res.y = D2 / D;
//         return res;
//     }
// }

// int main() {
//     point A, B, C, D;
//     cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
//     line AB = line(A, B);
//     line CD = line(C, D);
//     point ans = findMeetingPoint(AB, CD);
//     cout << fixed << setprecision(12) << ans.x << " " << ans.y;
//     return 0;
// }