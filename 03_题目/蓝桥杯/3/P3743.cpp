// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, p;
// vector<int> a, b;

// bool check(double x)
// {
//     double need = 0;
//     for (int i = 0; i < n; i++)
//     {
//         need += max(0.0, a[i] * x - b[i]);
//         if (need > p * x)
//         {
//             return false;
//         }
//     }

//     // 看当前需求是否能得到满足
//     return need <= p * x;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>p;
//         a.resize(n);
//         b.resize(n);

//         // 需要充电补充的部分为 sum(max(0, a * t - b))
//         // 即判断是否有 p * t >= sum(max(0, a * t - b))
//         // 随着 t 增大，左边增速为 p，右边为 sum(a)

//         // 故，若 p >= sum(a)，则可以一直使用下去

//         ll sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i]>>b[i];
//             sum += a[i];
//         }

//         if (p >= sum)
//         {
//             cout<<"-1"<<endl;
//             return 0;
//         }

//         double l = 0, r = 1e15;
//         // 二分答案（浮点数）
//         while (r - l > 1e-4)
//         {
//             double mid = (l + r) / 2;
//             if (check(mid))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid;
//             }
//         }

//         cout<<fixed<<setprecision(10)<<r<<endl;
//     }

//     return 0;
// }