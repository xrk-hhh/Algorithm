// 原始稿：04_训练与工具/牛客新手130题/10/70.cpp
// 原文行号：1-25；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
 	int y;	
    Point(int xx, int yy) : x(xx), y(yy) {}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算A点与B点之间的距离
     * @param point_A Point类 A点
     * @param point_B Point类 B点
     * @return double浮点型
     */
    double calculateDistance(Point point_A, Point point_B) {
        int x1 = point_A.x, y1 = point_A.y;
        int x2 = point_B.x, y2 = point_B.y;
        double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        return dis;
    }
};
