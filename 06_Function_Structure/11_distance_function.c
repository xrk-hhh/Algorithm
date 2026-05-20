// #include <stdio.h>
// #include <math.h>

// double dis(double a1, double b1, double a2, double b2)
// {
//     double a = fabs(a1 - a2);
//     double b = fabs(b1 - b2);
//     double res = sqrt(a * a + b * b);
//     return res;
// }

// int main()
// {
//     double x1, y1, x2, y2, x3, y3;
//     scanf("%lf %lf", &x1, &y1);
//     scanf("%lf %lf", &x2, &y2);
//     scanf("%lf %lf", &x3, &y3);

//     double res1 = dis(x1, y1, x2, y2);
//     double res2 = dis(x2, y2, x3, y3);
//     double res3 = dis(x1, y1, x3, y3);

//     double ans = res1 + res2 + res3;
    
//     printf("%.2f\n", ans);
    
//     return 0;
// }